workspace "Trail"
	architecture "x64"
	startproject  "Sandbox"
	buildoptions "/utf-8"
	
	configurations
	{
		"Debug","Release","Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Trail/vendor/GLFW/include"
IncludeDir["Glad"] = "Trail/vendor/Glad/include"
IncludeDir["ImGui"] = "Trail/vendor/imgui"

include "Trail/vendor/GLFW"
include "Trail/vendor/Glad"
include "Trail/vendor/imgui"


project "Trail"
	location "Trail"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" ..outputDir.. "%{prj.name}")
	objdir("bin-int/" ..outputDir.. "%{prj.name}")


	pchheader "trlpch.h"
	pchsource "Trail/src/trlpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links{
		"GLFW",
		"Glad",
		"opengl32.lib",
		"ImGui"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TRL_PLATFORM_WINDOWS",
			"TRL_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputDir .. "Sandbox/\"")
		}
	filter "configurations:Debug"
		defines "TRL_DEBUG"
		staticruntime "off"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "TRL_RELEASE"
		staticruntime "off"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "TRL_DIST"
		staticruntime "off"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	buildoptions "/utf-8"

	targetdir("bin/" ..outputDir.. "%{prj.name}")
	objdir("bin-int/" ..outputDir.. "%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"Trail/vendor/spdlog/include",
		"Trail/src"
	}
	links
	{
		"Trail"
	}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TRL_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "TRL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TRL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TRL_DIST"
		optimize "On"