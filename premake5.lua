workspace "LazyDog"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "LazyDog/vendor/GLFW/include"

include "LazyDog/vendor/GLFW"


project "LazyDog"
    location "LazyDog"
    kind "SharedLib"
    language "C++"
   
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "ldpch.h"
    pchsource "%{prj.name}/src/ldpch.cpp"

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines 
        {
            "LD_PLATFORM_WINDOWS",
            "LD_BUILD_DLL",
        }

        postbuildcommands
        {
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/%{cfg.buildtarget.name}")
		}
    
    filter "configurations:Debug"
        defines "LD_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "LD_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "LD_DIST"
        optimize "On"
    
    filter {"system:windows", "configurations:Debug"}
        buildoptions "/utf-8"
        
    
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs 
    {
        "LazyDog/vendor/spdlog/include",
        "LazyDog/src"
    }

    links 
    {
        "LazyDog"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "LD_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "LD_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "LD_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "LD_DIST"
        optimize "On"
    
    filter {"system:windows", "configurations:Debug"}
        buildoptions "/utf-8"