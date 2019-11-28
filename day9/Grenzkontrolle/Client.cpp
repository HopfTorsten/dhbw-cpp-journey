#include "Common.hpp"

int main(int argc, char **argv)
{
    std::cout << "Starting Client" << std::endl;
    boost::asio::io_service io_service;

    auto connection = std::make_shared<connection_t>(io_service);

    char buf[100];
    tcp::resolver resolver{io_service};
    tcp::resolver::query query(argv[1], argv[2]);
    auto it = resolver.resolve(query);

    auto read_handler2 = [connection](error_code_t e, size_t r) {
        std::cout << "Answer:" << connection->buf << std::endl;
    };

    auto write_handler = [connection, read_handler2](error_code_t e, size_t r) {
        if (!e)
        {
            std::cout << "Answer: " << connection->buf << std::endl;
            std::cout << "Wait for the reaction!" << std::endl;
            auto buf = boost::asio::buffer(connection->buf, 100);
            boost::asio::async_read(connection->_sock, buf, read_handler2);
        }
    };

    auto read_h = [connection, write_handler](error_code_t e, size_t r) {
        if (!e)
        {
            std::cout << "Content: " << connection->buf << std::endl;
            std::cout << "Enter your answer: ";
            std::string answer;
            std::getline(std::cin, answer);
            char cbuf[100];
            strcpy(cbuf,answer.c_str());
            auto buf = boost::asio::buffer(cbuf, 100);
            boost::asio::async_write(connection->_sock, buf, write_handler);
        }
    };

    auto conn_handler = [read_h, connection](const boost::system::error_code &ec, auto x) {
        if (!ec)
        {

            auto bbuf = boost::asio::buffer(connection->buf, 100);
            boost::asio::async_read(connection->_sock, bbuf, read_h);
        }
    };

    boost::asio::async_connect(connection->_sock, it, conn_handler);

    auto t = std::thread([&io_service]() { io_service.run(); });
    t.join();
    std::cout << "Closing Client" << std::endl;
}