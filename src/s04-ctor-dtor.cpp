#include <iostream>
#include "s25090/MojaStrukturaDtor.h"

auto main() -> int
{
    MojaStrukturaDtor mojaStruktura = MojaStrukturaDtor("napis");
}

MojaStrukturaDtor::MojaStrukturaDtor(std::string pStr)
{
    str = pStr;
}

MojaStrukturaDtor::~MojaStrukturaDtor()
{
    std::cout << "DESTRUCTION! " << str << std::endl;
}
