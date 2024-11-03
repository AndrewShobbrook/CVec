cmake_minimum_required(VERSION 3.13)
project(CVEC)

add_library(cvec cvec.c)
target_include_directories(cvec PUBLIC .)
