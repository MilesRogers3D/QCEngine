workspace "QCEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Distribution"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "QCEngine"
    location "QCEngine"
    kind "SharedLib"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "QC_PLATFORM_WINDOWS",
            "QC_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "QC_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "QC_RELEASE"
        optimize "On"

    filter "configurations:Distribution"
        defines "QC_DIST"
        optimize "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "QCEngine/vendor/spdlog/include",
        "QCEngine/src"
    }

    links
    {
        "QCEngine"
    }

    defines
    {
        "QC_PLATFORM_WINDOWS"
    }

    filter "configurations:Debug"
        defines "QC_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "QC_RELEASE"
        optimize "On"

    filter "configurations:Distribution"
        defines "QC_DIST"
        optimize "On"