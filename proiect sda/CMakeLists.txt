cmake_minimum_required(VERSION 3.21)
project(proiect_sda)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(proiect_sda
        Event/Event.cpp
        Event/Event.h
        main.cpp
        Messange/Message.cpp
        Messange/Message.h
        TAD/MultiDictionary.h
        TAD/multime.cpp
        TAD/multime.h
        Service/Network.cpp
        Service/Network.h
        Set.h
        Tests/Tests.cpp
        Tests/Tests.h
        User/User.cpp
        User/User.h
        UserInterface/UserInterface.cpp
        UserInterface/UserInterface.h
        )
