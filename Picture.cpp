//
// Created by Macbook Air on 10/6/19.
//

#ifndef ACCELERATED_CPP_PICTURE_CPP
#define ACCELERATED_CPP_PICTURE_CPP

#include <string>
#include <Ptr.h>
#include <vector>
#include <ostream>
#include <Student_info.cpp>
#include <Picture.h>

class Frame_Pic: public Pic_base {
    friend Picture frame(const Picture&);
    Ptr<Pic_base> p;
    Frame_Pic(const Ptr<Pic_base>& pic): p(pic) {
        //std::cout <r "Frame_Pic()" << std::endl;
    }

    wd_sz width() const override {
        return p->width() + 4;
    }

    ht_sz height() const override {
        return p->height() + 4;
    }

    void display(std::ostream& os, ht_sz row, bool do_pad) const override {
        if (row >= height()) {
            // out of range
            if (do_pad)
                pad(os, 0, width());
        } else {
            if (row == 0 || row == height() - 1) {
                // top or bottom row
                os << std::string(width(), '*');
            } else if (row == 1 || row == height() - 2) {
                // second from top or bottom row
                os << "*";
                pad(os, 1, width() - 1);
                os << "*";
            } else {
                // interior row
                os << "* ";
                p->display(os, row - 2, true);
                os << " *";
            }
        }
    };
};

class VCat_Pic: public Pic_base {
    friend Picture vcat(const Picture&, const Picture&);
    Ptr<Pic_base> top, bottom;
    VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b): top(t), bottom(b) { }

    wd_sz width() const override {
        return std::max(top->width(), bottom->width());
    };

    ht_sz height() const override {
        return top->height() + bottom->height();
    };

    void display(std::ostream& os, ht_sz row, bool do_pad) const override {
        wd_sz w = 0;
        if (row < top->height()) {
            top->display(os, row, do_pad);
            w = top->width();
        } else if (row < height()) {
            // we are in the bottom subpicture
            bottom->display(os, row - top->height(), do_pad);
            w = bottom->width();
        }
        if (do_pad)
            pad(os, w, width());
    };
};

class HCat_Pic: public Pic_base {
    friend Picture hcat(const Picture&, const Picture&);
    Ptr<Pic_base> left, right;

    HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r): left(l), right(r) {
        //std::cout << "HCat_Pic()" << std::endl;
    }

    wd_sz width() const override {
        return left->width() + right->width();
    };

    ht_sz height() const override {
        return left->height();
    };

    void display(std::ostream& os, ht_sz row, bool do_pad) const override {
        left->display(os, row, do_pad || row < right->height());
        right->display(os, row, do_pad);
    };
};

Picture frame(const Picture& pic) {
    return new Frame_Pic(pic.p);
}

Picture hcat(const Picture& l, const Picture& r) {
    return new HCat_Pic(l.p, r.p);
};

Picture vcat(const Picture& t, const Picture& b) {
    return new VCat_Pic(t.p, b.p);
};

using std::vector;
using std::string;
Picture histogram(const std::vector<Student_info>& students) {
    // begin with empty string values to avoid problems with null later on
    Picture names;
    Picture grades;

    // concatenate the names and grades of all students
    for (std::vector<Student_info>::const_iterator it = students.begin(); it != students.end(); ++it) {
        // concatenate first and second names and grades on first iteration
        if (it == students.begin()) {
            names = vcat(vector<string>(1, students[0].name()),
                         vector<string>(1, students[1].name()));
            grades = vcat(vector<string>(1, " " + string(students[0].grade() / 5, '=')),
                          vector<string>(1, " " + string(students[1].grade() / 5, '=')));
            it++;
        }

        // subsequently, concatenate previous value with next
        else {
            names = vcat(names, vector<string>(1, it->name()));
            grades = vcat(grades, vector<string>(1, " " + string(it->grade() / 5, '=')));
        }
    }

    // horizontally concatenate the name and grade pictures to combine them
    return hcat(names, grades);
}

std::ostream& operator<<(std::ostream& os, const Picture& picture) {
    const Pic_base::ht_sz ht = picture.p->height();

    for (Pic_base::ht_sz i = 0; i != ht; ++i) {
        picture.p->display(os, i, false);
        os << std::endl;
    }
    return os;
};

#endif //ACCELERATED_CPP_PICTURE_CPP