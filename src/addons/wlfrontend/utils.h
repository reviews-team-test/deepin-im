#ifndef UTILS_H
#define UTILS_H

template<auto F>
struct CallbackWrapper;

template<typename C, typename R, typename... Args, R (C::*F)(Args...)>
struct CallbackWrapper<F>
{
    static R func(void *userdata, Args... args)
    {
        auto *p = static_cast<C *>(userdata);
        return (p->*F)(args...);
    }
};

#endif // !UTILS_H