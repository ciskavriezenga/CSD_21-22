#include <iostream>
#include <unordered_set>

int main()
{
    std::unordered_set<std::string> waveFormTypes ({"sine", "saw", "square", "triangle"});

    std::cout << "\nThe waveFormTypes are:";

#if 1
    // use the 'old fashion' iterator
    for ( std::unordered_set<std::string>::iterator it = waveFormTypes.begin();
        it != waveFormTypes.end(); ++it )
#else
    // use the keyword auto - for versions of c++ 11 and higher
    for ( auto it = waveFormTypes.begin(); it != waveFormTypes.end(); ++it )
#endif
    {
        std::cout << " " << *it;
    }


    std::cout << "\n\nWe can check if the set contains an element: "
        << "set.find(element) != set.end();"
        << "\n\nWhen we check if the waveFormTypes set contains the string 'foo' "
        << "this results in: "
        << (waveFormTypes.find("foo") != waveFormTypes.end())
        << "\nWhen we check if the waveFormTypes set contains the string 'saw' "
        << "this results in: "
        << (waveFormTypes.find("saw") != waveFormTypes.end()) << std::endl;

}
