#ifndef Path_H
#define Path_H

#include <filesystem>
#include <string>
#include <vector>

namespace Utils
{
    typedef std::filesystem::path SysPath;
    namespace fs = std::filesystem;

    class Path
    {

    private:
        static std::string projectRootName;
        static SysPath root;
        static SysPath findRoot();

    public:
        static SysPath getSourcePath();

        static SysPath getSpaceShipSpritePath(std::string&& name);
        static SysPath getMazeSpritePath(std::string&& name);
        static SysPath getSoundPath(std::string&& name);
        static SysPath getFontPath(std::string&& name);

        template<typename... Args>
        static SysPath join(std::filesystem::path path, Args... args);
    };
}

/**
 * @brief Joins the given paths into a single path.
 * @param path The first path.
 * @param args The rest of the paths.
 * @return The joined path.
 */
template<typename... Args>
Utils::SysPath Utils::Path::join(SysPath path, Args... args)
{
    std::vector<std::string> paths = { std::string(args)... };
    for (const std::string& p : paths)
    {
        path /= p;
    }

    return path;
}

#endif // Path_H
