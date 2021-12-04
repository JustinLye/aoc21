#include <bitset>
#include <cassert>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


namespace aoc {
namespace utilities {
    namespace input {
        template<class T>
        class InputStream {
            std::ifstream m_Stream;
        protected:
            template<class Y = T>
            Y internal_get();
        public:
            InputStream(const char* file_path);
            virtual ~InputStream();
            
            bool fail() const noexcept;
            bool good() const noexcept;
            std::size_t size();
            
            virtual T get();
            void reset();
            
            bool operator!() const noexcept;
            operator bool() const noexcept;
        };

        template<std::size_t N>
        class BitStream :
            public InputStream<std::bitset<N>> {
        public:
            BitStream(const char* file_path);

            virtual std::bitset<N> get() override;
        };
    }
}}

template<class T>
template<class Y>
Y aoc::utilities::input::InputStream<T>::internal_get() {
    if (!good()) {
        throw std::runtime_error("Error! get failed because input stream is not available.");
    }
    Y output;
    m_Stream >> output;
    return output;
}

template<class T>
aoc::utilities::input::InputStream<T>::InputStream(const char* file_path) :
    m_Stream(file_path) {
    assert(m_Stream.good());
}

template<class T>
aoc::utilities::input::InputStream<T>::~InputStream() {

}

template<class T>
bool aoc::utilities::input::InputStream<T>::fail() const noexcept {
    return m_Stream.fail();
}

template<class T>
bool aoc::utilities::input::InputStream<T>::good() const noexcept {
    return m_Stream.good();

template<class T>
std::size_t aoc::utilities::input::InputStream<T>::size() {
    if (!good()) {
        throw std::runtime_error("Error! size failed because input stream is not available.");
    }
    auto current_pos = m_Stream.tellg();
    m_Stream.seekg(0, std::ios_base::end);
    auto buffer_size = m_Stream.tellg();
    m_Stream.seekg(current_pos);
    return buffer_size;
}

template<class T>
T aoc::utilities::input::InputStream<T>::get() {
    return internal_get();
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

template<std::size_t N>
aoc::utilities::input::BitStream<N>::BitStream(const char* file_path) :
    InputStream(file_path) {}

template<std::size_t N>
std::bitset<N> aoc::utilities::input::BitStream<N>::get() {
    auto input_string = internal_get<std::string>();
    if (fail()) {
        return {};
    }
    std::istringstream input_string_stream(input_string);
    std::bitset<N> output;
    input_string_stream >> output;
    return output;
}