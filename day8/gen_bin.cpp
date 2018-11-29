#include <fstream>
#include <iostream>
#include <algorithm>
void writeMessage(std::ofstream &stream, char *msg, int16_t size)
{
    if (!stream.is_open())
    {
        std::runtime_error err("Shit");
        throw err;
    }

    stream.write((char *)&size, sizeof(int16_t));
    std::reverse(msg, msg + size);
    for (int i = 0; i < size; ++i)
    {
        msg[i] = msg[i] + 1;
    }
    stream.write(msg, size);
}

int main(int argc, char **argv)
{
    int x = 100;
    std::string fileName = "bin_out";
    if (argc == 2)
    {
        x = atoi(argv[1]);
    }
    if(argc == 3){
        fileName = argv[2];
    }
    char *buf = new char[255];
    try
    {
        std::ofstream ofstream(fileName.c_str());
        for (auto i = 0; i < x; i++)
        {
            std::cin.getline(buf, 200);
            auto str_len = strlen(buf);
            writeMessage(ofstream, buf, str_len);
        }
        ofstream.close(); // yeah in exception case we're fucked. idk
    }
    catch (std::exception &ex)
    {
        printf("Shit that went wrong!");
    }

    delete[] buf;
}