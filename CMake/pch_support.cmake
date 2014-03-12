# MSVC PrecompiledHeader 
MACRO( MSVC_SET_PCH Target PrecompiledHeader PrecompiledSource)
  IF( MSVC )
    GET_FILENAME_COMPONENT(PrecompiledBasename
       ${PrecompiledHeader} NAME)

    SET_PROPERTY(SOURCE ${PrecompiledSource}
      APPEND
      PROPERTY
        COMPILE_FLAGS
          "/Yc\"${PrecompiledBasename}\"")

	SET_PROPERTY(TARGET ${Target}
      APPEND
      PROPERTY
        COMPILE_FLAGS
          "/Yu\"${PrecompiledBasename}\"")
  ENDIF( MSVC )
ENDMACRO( MSVC_SET_PCH )

MACRO(RUNTIME_LIBRARY_OPTION Config Option)
	STRING(TOUPPER ${Config} Config2)
	SET(FLAGS_VARNAME "CMAKE_CXX_FLAGS_${Config2}")
	SET(FLAGS ${${FLAGS_VARNAME}})

	STRING(REGEX REPLACE "/MD ?" "${Option} " FLAGS ${FLAGS}})
	STRING(REGEX REPLACE "/MDd ?" "${Option} " FLAGS ${FLAGS})
	STRING(REGEX REPLACE "/MT ?" "${Option} " FLAGS ${FLAGS})
	STRING(REGEX REPLACE "/MTd ?" "${Option} " FLAGS ${FLAGS})

	if(NOT ${FLAGS} MATCHES "${Option}")
		SET(FLAGS "${FLAGS} ${Option}")
	ENDIF()
	SET(${FLAGS_VARNAME} ${FLAGS})
ENDMACRO()