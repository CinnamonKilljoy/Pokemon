/**
 * @author  Zimon Kuhs (zimonkuhs@gmail.com)
 * @brief   File functionality.
 * @date    2022-01-25
 */
#ifndef _CK_FILES_HPP_
#define _CK_FILES_HPP_

#include <json/json.h>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

#include "log.hpp"
#include "errors.hpp"

namespace filesystem = std::filesystem;

namespace ck::file {

std::string fromRoot(const std::string &fileName);

Json::Value asJSON(const std::string &fileName);

std::vector<std::string> fileAsLines(const std::string &fileName);

}   // namespace ck::files

#endif  // _CK_FILES_HPP_
