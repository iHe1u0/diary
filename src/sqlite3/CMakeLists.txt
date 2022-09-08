cmake_minimum_required(VERSION 3.0.0)

project(sqlite3)

aux_source_directory(. SQLITE_SRC)

add_library(sqlite3 ${SQLITE_SRC})