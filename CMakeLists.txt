cmake_minimum_required(VERSION 3.27)
project(NocturneSDK VERSION 0.1)

add_subdirectory(libc/)

install(FILES ${CMAKE_SOURCE_DIR}/tools/nocturneos-cc.py
        DESTINATION ./bin/
        PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                    GROUP_EXECUTE GROUP_READ
                    WORLD_EXECUTE WORLD_READ)
