#include "errors.hpp"
#include "files.hpp"

using namespace ck::error;

namespace ck::file {

std::string fromRoot(const std::string &fileName) {
    return std::filesystem::absolute("..") / fileName;
}

Json::Value asJSON(const std::string &fileName) {
    if (!filesystem::exists(fileName)) {
        throw error::FileError("Could not find " + fileName + ".");
    }

    Json::Value root;
    std::ifstream file(fromRoot(fileName));
    file >> root;
    file.close();
    return root;
}

std::vector<std::string> fileAsLines(const std::string &fileName) {
    std::string file = std::string(__FILE__);
    std::string absolute = std::filesystem::absolute(file + "/../../" + fileName).string();

    if (!filesystem::exists(absolute)) {
        throw error::FileError("Could not parse " + fileName + "; file doesn't exist!");
    }

    std::ifstream inStream = std::ifstream(absolute);

    std::string line = "\0";
    std::vector<std::string> lines = std::vector<std::string>();
    while(std::getline(inStream, line)) {
        lines.push_back(line);
    }
    inStream.close();

    return lines;
}

} // namespace ck::files
