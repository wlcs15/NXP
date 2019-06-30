// Copyright 2019 OwlThree LLC
// Permission is hereby granted, free of charge, to any person obtaining a copy of this
// software and associated documentation files (the "Software"), to deal in the Software
// without restriction, including without limitation the rights to use, copy, modify,
// merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to the following 
// conditions: 
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software. 
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT,  TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.

// @author Charles L. Sherman
// @author OwlThree LLC
// @version
// @since v1.0

#include <iostream>
#include <iterator>
#include <algorithm>
#include <typeinfo>
#define BOOST_COMP_IAR
//#define BOOST_DISABLE_THREADS
#define BOOST_HAS_THREADS
#define BOOST_THREAD_PROVIDES_FUTURE
#include <boost/thread.hpp>
#include <boost/thread/future.hpp>
#include <functional>
#include <iostream>
#include <boost\lambda\lambda.hpp>
#include <boost\fiber\future\future.hpp>

using namespace std;

void accumulate(boost::promise<int> &p)
{
  int sum = 0;
  for (int i = 0; i < 5; ++i)
    sum += i;
  p.set_value(sum);
}

int main()
{
  boost::promise<int> p;
  boost::future<int> f = p.get_future();
  boost::thread t{accumulate, std::ref(p)};
  std::cout << f.get() << '\n';
}

namespace boost {
namespace fibers {

template< typename R >
class future {
public:
    future() noexcept;

    future( future const& other) = delete;

    future & operator=( future const& other) = delete;

    future( future && other) noexcept;

    future & operator=( future && other) noexcept;

    ~future();

    bool valid() const noexcept;

    shared_future< R > share();

    R get();    // member only of generic future template
    R & get();  // member only of future< R & > template specialization
    void get(); // member only of future< void > template specialization

    std::exception_ptr get_exception_ptr();

    void wait() const;

    template< class Rep, class Period >
    future_status wait_for(
        std::chrono::duration< Rep, Period > const& timeout_duration) const;

    template< typename Clock, typename Duration >
    future_status wait_until(
        std::chrono::time_point< Clock, Duration > const& timeout_time) const;
};

template< typename R >
class shared_future {
public:
    shared_future() noexcept;

    ~shared_future();

    shared_future( shared_future const& other);

    shared_future( future< R > && other) noexcept;

    shared_future( shared_future && other) noexcept;

    shared_future & operator=( shared_future && other) noexcept;

    shared_future & operator=( future< R > && other) noexcept;

    shared_future & operator=( shared_future const& other) noexcept;

    bool valid() const noexcept;

    R const& get(); // member only of generic shared_future template
    R & get();      // member only of shared_future< R & > template specialization
    void get();     // member only of shared_future< void > template specialization

    std::exception_ptr get_exception_ptr();

    void wait() const;

    template< class Rep, class Period >
    future_status wait_for(
        std::chrono::duration< Rep, Period > const& timeout_duration) const;

    template< typename Clock, typename Duration >
    future_status wait_until(
        std::chrono::time_point< Clock, Duration > const& timeout_time) const;
};

}}
