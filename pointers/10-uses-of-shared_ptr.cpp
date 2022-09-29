// shared_ptr-examples.cpp
// The following examples assume these declarations:
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Base
{
public:
    Base() { std::cout << "Base::Base()" << std::endl; }

    Base(int x) { std::cout << "Base::Base(1 arg)" << std::endl; }

    void
    func() { std::cout << "Base::func()" << std::endl; }
};
//
struct MediaAsset
{
    virtual ~MediaAsset() = default; // make it polymorphic
};

struct Song : public MediaAsset
{
    std::string artist;
    std::string title;
    Song(const std::string &artist_, const std::string &title_) : artist{artist_}, title{title_} {}
};

struct Photo : public MediaAsset
{
    std::string date;
    std::string location;
    std::string subject;
    Photo(
        const std::string &date_,
        const std::string &location_,
        const std::string &subject_) : date{date_}, location{location_}, subject{subject_} {}
};

using namespace std;

int main()
{
    // Use make_shared function when possible.
    auto SPB1 = make_shared<Song>("The Beatles", "Im Happy Just to Dance With You");

    // Ok, but slightly less efficient.
    // Note: Using new expression as constructor argument
    // creates no named variable for other code to access.
    shared_ptr<Base> PSB2(new Base(1));
    shared_ptr<Song> sp2(new Song("Lady Gaga", "Just Dance"));

    // When initialization must be separate from declaration, e.g. class members,
    // initialize with nullptr to make your programming intent explicit.
    shared_ptr<Base> SPB3(nullptr);
    shared_ptr<Song> sp5(nullptr);
    // Equivalent to: shared_ptr<Song> sp5;
    //...
    SPB3 = make_shared<Base>(1);
    sp5 = make_shared<Song>("Elton John", "I'm Still Standing");

    return 0;
}