workspace "Trail"
	architecture "x64"
	startupproject "Sandbox"
	buildoptions "/utf-8"
	
	configurations
	{
		"Debug","Release","Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Trail"
	location "Trail"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" ..outputDir.. "%{prj.name}")
	objdir("bin-int/" ..outputDir.. "%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"%{prj.name}/src"
		"%{prj.name}/vendor/spdlog/include;"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TRL_PLATFORM_WINDOWS",
			"TRL_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputDir .. "Sandbox/\"")
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