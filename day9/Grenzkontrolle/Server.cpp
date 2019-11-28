#include "Common.hpp"
#include <vector>
class Server
{
public:
    Server();
    ~Server();
    void start();
    void handle_accept(error_code_t ec, std::shared_ptr<connection_t> con);
    void write_greeting(std::shared_ptr<connection_t> con);
    void listen_for_answer(std::shared_ptr<connection_t> con);
    void handle_client_answer(std::shared_ptr<connection_t> con);
    void handle_write(error_code_t ec, size_t);

private:
    std::vector<std::shared_ptr<connection_t>> _connections;
    boost::asio::io_service _io_service;
    tcp::acceptor _acceptor;
    tcp::endpoint _endpoint{tcp::v4(), 8888};
    std::unique_ptr<std::thread> _thread;
};

Server::Server() : _io_service{}, _acceptor(this->_io_service)
{
}

Server::~Server()
{
}

void Server::start()
{
    _acceptor.open(_endpoint.protocol());
    _acceptor.bind(_endpoint);
    _acceptor.listen();

    auto connection = std::make_shared<connection_t>(_io_service);
    _acceptor.async_accept(connection->_sock, [this, connection](error_code_t ec) { this->handle_accept(ec, connection); });
    _thread = std::make_unique<std::thread>([this]() { _io_service.run(); });
    _thread->join();
}

void Server::handle_accept(error_code_t ec, std::shared_ptr<connection_t> con)
{
    if (!ec)
    {
        write_greeting(con);
        // ready for new connections
        auto new_connection = std::make_shared<connection_t>(_io_service);
        _acceptor.async_accept(new_connection->_sock, [this, new_connection](error_code_t ec) { this->handle_accept(ec, new_connection); });
    }
}

void Server::handle_client_answer(std::shared_ptr<connection_t> con)
{
    std::string client_answer = con->buf;
    std::cout << "Got the following answer" << client_answer << std::endl;
    std::string server_answer = (0 == client_answer.compare("Guten Tag")) ? "Weiterfahren" : "Abgelehnt";

    strcpy(con->buf, server_answer.c_str());

    auto write_handler = [con](error_code_t ec, size_t written) {
        if (!ec)
        {
            std::cout << "Fertig!" << std::endl;
        }
    };
    auto buf = boost::asio::buffer(con->buf, 100);
    boost::asio::async_write(con->_sock, buf, write_handler);
}

void Server::listen_for_answer(std::shared_ptr<connection_t> con)
{
    auto read_handler = [this, con](error_code_t ec, size_t read) {if(!ec){this->handle_client_answer(con);}else{std::cout << ec.message() << std::endl;} };
    auto buf = boost::asio::buffer(con->buf, 100);
    boost::asio::async_read(con->_sock, buf, read_handler);
    std::cout << "Listening for answer" << std::endl;
}

void Server::write_greeting(std::shared_ptr<connection> con)
{
    auto write_handler = [this, con](error_code_t ec, size_t written) {
        if (!ec)
        {
            std::cout << "Message of " << written << "bytes written!" << std::endl;
            listen_for_answer(con);
        }
    };
    strcpy(con->buf, "Guten Tag!");
    std::cout << con->buf << std::endl;
    auto buf = boost::asio::buffer(con->buf, 100);
    boost::asio::async_write(con->_sock, buf, write_handler);
}

int main()
{
    Server serv;
    serv.start();
}