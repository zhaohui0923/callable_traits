/*

@copyright Barrett Adair 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/

#ifndef BOOST_CLBL_TRTS_IS_INVOCABLE_HPP
#define BOOST_CLBL_TRTS_IS_INVOCABLE_HPP

#include <boost/callable_traits/detail/core.hpp>
#include <boost/callable_traits/detail/is_invocable_impl.hpp>

namespace boost { namespace callable_traits {

//[ is_invocable_hpp
/*`[section:ref_is_invocable is_invocable]
[heading Header]
``#include <boost/callable_traits/is_invocable.hpp>``
[heading Definition]
*/

// inherits from either std::true_type or std::false_type
template<typename T, typename... Args>
struct is_invocable;

//<-
template<typename T, typename... Args>
struct is_invocable : detail::is_invocable_impl<T, Args...>::type {
    using type = typename detail::is_invocable_impl<T, Args...>::type;
};

#ifdef BOOST_CLBL_TRTS_DISABLE_VARIABLE_TEMPLATES

template<typename T, typename... Args>
struct is_invocable_v {
    static_assert(std::is_same<T, detail::dummy>::value,
        "Variable templates not supported on this compiler.");
};

#else
//->
// only available when variable templates are supported
template<typename T, typename... Args>
//<-
BOOST_CLBL_TRAITS_INLINE_VAR
//->
constexpr bool is_invocable_v = //see below
//<-
    detail::is_invocable_impl<detail::traits<T>, Args...>::type::value;

#endif

}} // namespace boost::callable_traits
//->

/*`
[heading Constraints]
* none

[heading Behavior]
* polyfill for c++1z `std::is_invocable`

[heading Compatibility Notes]
TODO

[heading Input/Output Examples]
[table
    [[`T`]                              [`is_invocable<T>`]]
    [[`todo`]                           [`todo`]]
]

[heading Example Program]
[import ../example/is_invocable.cpp]
[is_invocable]
[endsect]
*/
//]

#endif // #ifndef BOOST_CLBL_TRTS_IS_INVOCABLE_HPP
