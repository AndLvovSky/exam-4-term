template <typename T>
struct Hashable {

    virtual unsigned int getHashCode() = 0;

    virtual bool operator == (const T& other) = 0;

};
