#ifndef RESULT_H
#define RESULT_H

namespace Test
{
    class RESULT
    {
    public:
        static RESULT SUCCESS()
        {
            return {RESULT::Type::SUCCESS};
        }

        static RESULT FAILURE()
        {
            return {RESULT::Type::FAILURE};
        }

        enum class Type
        {
            SUCCESS,
            FAILURE
        };

        RESULT(Type type) : type(type) {}

        operator bool() const
        {
            return type == Type::SUCCESS;
        }

        bool operator==(bool value) const
        {
            return static_cast<bool>(*this) == value;
        }

        bool operator!=(bool value) const
        {
            return !(*this == value);
        }

    private:
        Type type;
    };

}

#endif //RESULT_H
