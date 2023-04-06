#ifndef __CK_OPTIONS_HPP__
#define __CK_OPTIONS_HPP__

#include <map>
#include <string>
#include <vector>

namespace ck {

class Options final {

    public:

        bool asBool(const std::string &name) const;
        double asFloat(const std::string &name) const;
        int asInt(const std::string &name) const;
        std::string get(const std::string &name) const;
        bool has(const std::string &name) const;
        std::vector<char> keys() const;
        std::vector<std::string> list(const std::string &name) const;

        static Options get();
        static Options set(std::vector<std::string> arguments);

    private:
        Options();
        Options(std::vector<std::string> arguments);
        Options operator=(const Options &other) = delete;

        static Options *instance;
        std::map<std::string, std::vector<std::string>> options {};
};

}

#endif  // __CK_OPTIONS_HPP__
