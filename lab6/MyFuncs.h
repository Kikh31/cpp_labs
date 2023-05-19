#pragma once

template<class T>
bool positive(T x) {
    return x > 0;
}

template<typename It, typename P>
bool my_any_of(It first, It last, P predicate) {

    for (; first != last; ++first) {
        if (predicate(*first)) {
            return true;
        }
    }
    return false;
}

template<typename It, typename P>
bool my_is_partitioned(It first, It last, P predicate) {

    for (; first != last; ++first) {
        if (!predicate(*first)) {
            break;
        }
    }
    if (first == last) {
        return true;
    }
    ++first;
    for (; first != last; ++first) {
        if (predicate(*first)) {
            return false;
        }
    }
    return true;
}

template<typename It, typename P>
bool my_is_palindrome(It first, It last, P predicate) {

    last--;
    for (; first <= last; ++first, --last) {
        if (predicate(*first) != predicate(*last)) {
            return false;
        }
    }
    return true;
}
