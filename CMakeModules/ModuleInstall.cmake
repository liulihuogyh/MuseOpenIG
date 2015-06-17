SET(INSTALL_INCDIR include)
SET(INSTALL_BINDIR bin)
IF(WIN32)
    SET(INSTALL_LIBDIR bin)
    SET(INSTALL_ARCHIVEDIR lib)
ELSE()
    SET(INSTALL_LIBDIR ${CMAKE_INSTALL_LIBDIR})
    SET(INSTALL_ARCHIVEDIR ${CMAKE_INSTALL_LIBDIR})
ENDIF()

SET(HEADERS_GROUP "Header Files")

SOURCE_GROUP(
    ${HEADERS_GROUP}
    FILES ${LIB_PUBLIC_HEADERS}
)

INSTALL(
    TARGETS ${LIB_NAME}
    EXPORT openig-targets
    RUNTIME DESTINATION ${INSTALL_BINDIR} COMPONENT libopenig
    LIBRARY DESTINATION ${INSTALL_LIBDIR} COMPONENT libopenig
    ARCHIVE DESTINATION ${INSTALL_ARCHIVEDIR} COMPONENT libopenig-dev
)

# FIXME: Do not run for OS X framework
INSTALL(
    FILES        ${LIB_PUBLIC_HEADERS}
    DESTINATION ${INSTALL_INCDIR}/${LIB_NAME}
    COMPONENT libopenig-dev
)
