#ifndef TBOOL_H
#define TBOOL_H

#include <typeinfo>

namespace tb {

    enum tboolValues {
        TRUE = 1,
        NEUTRAL = 0,
        FALSE = -1
    };

    int normi(int f) noexcept(true) {
        return (!f)? NEUTRAL : (f < NEUTRAL)? FALSE : TRUE; 
    }

    #define TEMPL(T) template <typename T>

    class tbool {
    protected:
        int boolean;
    public:

        // Boolean constructor
        tbool(bool param) :
            tbool{(param)? 1 : -1} { }

        // Int constructor
        tbool(int b = 0) :
            boolean{b} { };

        // Returns int boolean value
        int get() { return this->boolean; }

        // Returns true if value is 1 or 0, and false if the value is -1.
        bool toBool() { return boolean >= 0; }

        // Sets boolean value as int 
        TEMPL(T) void setBool(T param) { boolean = normi(static_cast<int>(param)); }
        
        constexpr tbool& operator= (const tbool& param);

        TEMPL(T) friend tbool& operator+= (tbool& param1, const T param2);

        TEMPL(T) friend tbool operator+ (tbool param1, const T param2);
        TEMPL(T) friend tbool operator- (tbool param1, const T param2);
        TEMPL(T) friend tbool operator* (tbool param1, const T param2);
        TEMPL(T) friend tbool operator/ (tbool param1, const T param2);

        // Comparison operators will always return a true or false value
        // A Neutral value is considered truthy!!! 
        TEMPL(T) friend bool operator>  (tbool param1, const T param2);
        TEMPL(T) friend bool operator<  (tbool param1, const T param2);
        TEMPL(T) friend bool operator>= (tbool param1, const T param2);
        TEMPL(T) friend bool operator<= (tbool param1, const T param2);
        TEMPL(T) friend bool operator&& (tbool param1, const T param2);
        TEMPL(T) friend bool operator|| (tbool param1, const T param2);

        //TEMPL(T) constexpr friend bool operator== (tbool param1, const T param2);
        TEMPL(T) constexpr friend bool operator== (const T param2, tbool param1);

        TEMPL(T) constexpr friend bool operator!= (tbool param1, const T param2);
        
        operator int() const;
    };

    constexpr tbool& tbool::operator= (const tbool& param) {
        boolean = param.boolean;
        return *this;
    }    

    TEMPL(T) tbool& operator+= (tbool& param1, const T param2) {
        param1.setBool(normi(param1.get() + static_cast<int>(param2)));
        return param1;
    }

    TEMPL(T)
    tbool operator+ (tbool param1, const T param2) {
        return tbool(normi(param1.get() + static_cast<int>(param2)));
    }

    TEMPL(T)
    tbool operator- (tbool param1, const T param2) {
        return tbool(normi(param1.get() - static_cast<int>(param2)));
    }
    
    TEMPL(T)
    tbool operator* (tbool param1, const T param2) {
        return tbool(normi(param1.get() * static_cast<int>(param2)));
    }

    TEMPL(T)
    tbool operator/ (tbool param1, const T param2) {
        return tbool(normi(param1.get() / static_cast<int>(param2)));
    }

    TEMPL(T)
    bool operator> (tbool param1, const T param2) {
        return param1.toBool() > param2;
    }
    
    TEMPL(T)
    bool operator>= (tbool param1, const T param2) {
        return param1.toBool() >= param2;
    }
    
    TEMPL(T)
    bool operator< (tbool param1, const T param2) {
        return param1.toBool() < param2;
    }
    
    TEMPL(T)
    bool operator<= (tbool param1, const T param2) {
        return param1.toBool() <= param2;
    }

    TEMPL(T)
    bool operator&& (tbool param1, const T param2) {
        return param1.toBool() && param2;
    }

    TEMPL(T)
    bool operator|| (tbool param1, const T param2) {
        
        return param1.toBool() || param2;
    }

    TEMPL(T)
    constexpr bool operator== (const T param2, tbool param1) {
        if (typeid(param2) == typeid(bool))
            return param1.toBool() == param2;
        return (static_cast<int>(param2) == param1.get());
    }

    TEMPL(T)
    constexpr bool operator!= (const tbool param1, const T param2) {
        return !(param1 == param2);
    }

    tbool::operator int() const {
        return boolean;
    }
}

#endif
