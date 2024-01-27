cmake_minimum_required(VERSION 3.24)
project(project_oop)

set(CMAKE_CXX_STANDARD 20)

add_executable(project_oop main.cpp user.h product.h database.h customer.h seller.h sellers_DB.h products_DB.h customers_DB.h)
