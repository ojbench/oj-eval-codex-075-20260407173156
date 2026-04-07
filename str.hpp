#pragma once
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstddef>

class str {
private:
    char *data_;
    std::size_t size_;
    std::size_t cap_;

    void allocate(std::size_t n) {
        cap_ = n + 1;
        data_ = new char[cap_];
        data_[n] = '\0';
        size_ = n;
    }

    static std::size_t cstrlen(const char *s) {
        return s ? std::strlen(s) : 0;
    }

    void assign_from_cstr(const char *s) {
        std::size_t n = cstrlen(s);
        if (cap_ <= n) {
            delete[] data_;
            allocate(n);
        }
        if (n) std::memcpy(data_, s, n);
        data_[n] = '\0';
        size_ = n;
    }

public:
    // Default: empty string
    str() : data_(nullptr), size_(0), cap_(0) {
        allocate(0);
    }

    // Construct from single char
    explicit str(const char &c) : data_(nullptr), size_(0), cap_(0) {
        allocate(1);
        data_[0] = c;
    }

    // Construct from const char* rvalue
    explicit str(const char *&& s_) : data_(nullptr), size_(0), cap_(0) {
        assign_from_cstr(s_);
    }

    // Also allow const char* lvalue construction (convenience)
    explicit str(const char *s_) : data_(nullptr), size_(0), cap_(0) {
        assign_from_cstr(s_);
    }

    // Copy constructor
    str(const str &other) : data_(nullptr), size_(0), cap_(0) {
        allocate(other.size_);
        if (other.size_) {
            std::memcpy(data_, other.data_, other.size_);
        }
        data_[size_] = '\0';
    }

    // Copy assignment
    str &operator=(const str &other) {
        if (this == &other) return *this;
        if (cap_ <= other.size_) {
            delete[] data_;
            allocate(other.size_);
        }
        if (other.size_) {
            std::memcpy(data_, other.data_, other.size_);
        }
        size_ = other.size_;
        data_[size_] = '\0';
        return *this;
    }

    // Assign from const char* rvalue
    str &operator=(const char *&& s_) {
        assign_from_cstr(s_);
        return *this;
    }

    // Convenience: assign from const char* lvalue too
    str &operator=(const char *s_) {
        assign_from_cstr(s_);
        return *this;
    }

    // Indexing (0-based)
    char &operator[](std::size_t pos) {
        return data_[pos];
    }

    // Length
    std::size_t len() const { return size_; }

    // Join: concatenate elements of strs, inserting *this as separator
    str join(const std::vector<str> &strs) const {
        if (strs.empty()) {
            return str();
        }
        std::size_t sep_len = size_;
        std::size_t total = 0;
        for (const auto &s : strs) total += s.size_;
        if (strs.size() >= 2) total += sep_len * (strs.size() - 1);

        str result;
        if (result.cap_ <= total) {
            delete[] result.data_;
            result.allocate(total);
        }
        std::size_t pos = 0;
        for (std::size_t i = 0; i < strs.size(); ++i) {
            const str &part = strs[i];
            if (part.size_) {
                std::memcpy(result.data_ + pos, part.data_, part.size_);
                pos += part.size_;
            }
            if (i + 1 < strs.size() && sep_len) {
                std::memcpy(result.data_ + pos, data_, sep_len);
                pos += sep_len;
            }
        }
        result.size_ = pos;
        result.data_[pos] = '\0';
        return result;
    }

    // Slice [l, r)
    str slice(std::size_t l, std::size_t r) const {
        if (l > r) return str();
        if (l > size_) return str();
        if (r > size_) r = size_;
        std::size_t n = (r >= l) ? (r - l) : 0;
        str out;
        if (out.cap_ <= n) {
            delete[] out.data_;
            out.allocate(n);
        }
        if (n) {
            std::memcpy(out.data_, data_ + l, n);
        }
        out.size_ = n;
        out.data_[n] = '\0';
        return out;
    }

    ~str() { delete[] data_; }
};
