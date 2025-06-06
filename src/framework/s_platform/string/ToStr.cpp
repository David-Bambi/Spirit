    #include <string/ToStr.hpp>
    
    std::string ToStr::Vec(const std::vector<unsigned int> vec, const short nbcol)
    {
        std::string ret = "";
        short countothree = 0;
        for (const auto& unsint : vec)
        {
            if (++countothree % 3 == 0)
                ret += "\n";

            ret += std::to_string(unsint);
        }

        return ret;
    };