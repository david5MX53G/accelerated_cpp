//
// Created by Macbook Air on 12/13/19.
//

#ifndef ACCELERATED_CPP_PICTURE_H
#define ACCELERATED_CPP_PICTURE_H
#include <vector>
#include <Student_info.h>
#include <string>
#include <ostream>
#include <Ptr.h>

class Frame_Pic;
class HCat_Pic;
class VCat_Pic;
class Picture;

class Pic_base {
    friend std::ostream& operator<<(std::ostream&, const Picture&);
    friend class Frame_Pic;
    friend class HCat_Pic;
    friend class VCat_Pic;
    friend class String_Pic;

    typedef std::vector<std::string>::size_type ht_sz;
    typedef std::string::size_type wd_sz;

    virtual wd_sz width() const = 0;
    virtual ht_sz height() const = 0;
    virtual void display(std::ostream&, ht_sz, bool) const = 0;

public:
    virtual ~Pic_base() { };

protected:
    static void pad(std::ostream& os, wd_sz beg, wd_sz end) {
        while (beg != end) {
            os << " ";
            ++beg;
        }
    }
};

class String_Pic: public Pic_base {
    friend class Picture;
    std::vector<std::string> data;
    String_Pic(const std::vector<std::string>& v): data(v) { }

    ht_sz height() const override {
        return data.size();
    }

    wd_sz width() const override {
        Pic_base::wd_sz n = 0;
        for (Pic_base::ht_sz i = 0; i != data.size(); ++i)
            n = std::max(n, data[i].size());
        return n;
    };

    void display(std::ostream& os, ht_sz row, bool do_pad) const override {
        wd_sz start = 0;

        // write the row, if we're still in range
        if (row < height()) {
            os << data[row];
            start = data[row].size();
        }

        // pad the output, if necessary
        if (do_pad) {
            pad(os, start, width());
        }
    };
};

class Picture {
    friend std::ostream& operator<<(std::ostream&, const Picture&);
    friend Picture frame(const Picture&);
    friend Picture hcat(const Picture&, const Picture&);
    friend Picture vcat(const Picture&, const Picture&);

public:
    Picture() = default;
    Picture(const std::vector<std::string>& v): p(new String_Pic(v)) { }

private:
    Picture(Pic_base* ptr): p(ptr) { }
    Ptr<Pic_base> p;
};


Picture histogram(const std::vector<Student_info>& students);
Picture vcat(const Picture& t, const Picture& b);
Picture hcat(const Picture& l, const Picture& r);
Picture frame(const Picture& pic);
std::ostream& operator<<(std::ostream& os, const Picture& picture);

#endif //ACCELERATED_CPP_PICTURE_H
