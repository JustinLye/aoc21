#include <cassert>
#include <fstream>
#include <vector>


namespace aoc {
namespace utilities {
    namespace input {
        template<class T>
        class InputStream {
            std::ifstream m_Stream;
        public:
            InputStream(const char* file_path);
            
            bool fail() const noexcept;
            bool good() const noexcept;
            
            T get();
            void reset();
            
            bool operator!() const noexcept;
            operator bool() const noexcept;
        };
    }
}}

template<class T>
aoc::utilities::input::InputStream<T>::InputStream(const char* file_path) :
    m_Stream(file_path) {
    assert(m_Stream.good());
}

template<class T>
bool aoc::utilities::input::InputStream<T>::fail() const noexcept {
    return m_Stream.fail();
}

template<class T>
bool aoc::utilities::input::InputStream<T>::good() const noexcept {
    return m_Stream.good();
}

template<class T>
T aoc::utilities::input::InputStream<T>::get() {
    if (!good()) {
        throw std::runtime_error("Error! get failed because input stream is not available.");
    }
    T output;
    m_Stream >> output;
    return output;
}

template<class T>
void aoc::utilities::input::InputStream<T>::reset() {
    m_Stream.clear();
    m_Stream.seekg(std::ios::beg);
}

template<class T>
bool aoc::utilities::input::InputStream<T>::operator!() const noexcept {
    return !m_Stream;
}

template<class T>
aoc::utilities::input::InputStream<T>::operator bool() const noexcept {
    return static_cast<bool>(m_Stream);
}