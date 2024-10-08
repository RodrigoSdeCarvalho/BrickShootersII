#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <linux/limits.h>
#endif

#include <string>

#include "Debug/Trace.h"

#include "Utils/Path.h"

namespace Utils
{
    SysPath Path::root = Path::findRoot();

    /**
     * @brief Finds the root directory of the project.
     * @return The root directory of the project.
     */
    SysPath Path::findRoot() {
        #ifdef _WIN32
            Debug::Trace<Path, SHOW>() << "Windows: Finding root directory of the project..." << Debug::endl;
            char buffer[MAX_PATH];
                GetModuleFileName(nullptr, buffer, MAX_PATH);
                return fs::path(buffer).parent_path();
        #else
            Debug::Trace<Path, SHOW>() << "Linux: Finding root directory of the project..." << Debug::endl;

            char buffer[PATH_MAX];
            ssize_t len = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
            if (len != -1) {
                buffer[len] = '\0';
                SysPath root_path = fs::path(buffer).parent_path();

                Debug::Trace<Path, SHOW>() << "Root directory of the project: " << root_path << Debug::endl;

                return root_path;
            }

            throw std::runtime_error("Could not find root directory of the project.");
        #endif
    }

    SysPath Path::getSourcePath() {
        SysPath base = Path::root;
        SysPath source = base / "src";

        return source;
    }

    SysPath Path::getSpaceShipSpritePath(std::string&& name) {
        SysPath spaceShipSpritePath = Path::join(Path::root, "assets", "sprites", "space_ships", name);

        return spaceShipSpritePath;
    }

    SysPath Path::getMazeSpritePath(std::string&& name) {
        SysPath spaceShipSpritePath = Path::join(Path::root, "assets", "sprites", "maze", name);

        return spaceShipSpritePath;
    }

    SysPath Path::getSoundPath(std::string&& name) {
        SysPath spaceShipSpritePath = Path::join(Path::root, "assets", "sounds", name);

        return spaceShipSpritePath;
    }

    SysPath Path::getFontPath(std::string&& name) {
        SysPath spaceShipSpritePath = Path::join(Path::root, "assets", "fonts", name);

        return spaceShipSpritePath;
    }

} // namespace Utils
