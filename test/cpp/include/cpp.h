#ifndef CPP_H
#define CPP_H

/* This generated file contains includes for project dependencies */
#include <cpp/bake_config.h>
#include <string>
#include <vector>
#include <stddef.h>

struct Position {
    float x;
    float y;
};

struct Velocity {
    float x;
    float y;
};

struct Mass {
    float value;
};

struct Rotation {
    float value;
};

struct Tag { };

struct Self {
    flecs::entity_view value;
};

enum Number {
    One = 1,
    Two = 2,
    Three = 3
};

class Pod {
public:
    struct Child { };

    Pod() {
        ctor_invoked ++;
        value = 10;
    }

    Pod(int v) {
        ctor_invoked ++;
        value = v;
    }    

    ~Pod() {
        dtor_invoked ++;
    }

    Pod(const Pod& obj) {
        copy_ctor_invoked ++;
        this->value = obj.value;
    }

    Pod(Pod&& obj) noexcept {
        move_ctor_invoked ++;
        this->value = obj.value;
    }

    Pod& operator=(const Pod& obj) {
        copy_invoked ++;
        this->value = obj.value;
        return *this;
    }

    Pod& operator=(Pod&& obj) noexcept {
        move_invoked ++;
        this->value = obj.value;
        return *this;
    }   

    int value;

    static int ctor_invoked;
    static int dtor_invoked;
    static int copy_invoked;
    static int move_invoked;
    static int copy_ctor_invoked;
    static int move_ctor_invoked;
};

/**
 * A class that meticulously tracks all operations affecting its lifecycle,
 * including construction, assignment, and destruction.
 *
 * Unlike with Pod, these statistics are tracked per object,
 * which allows for more fine-grained tests.
 */
struct LifecycleTracker
{
    enum class Constructor
    {
        default_,
        copy,
        move,
    };

    Constructor constructed_via;
    int         times_destructed{};

    int         times_copy_assigned_into{};
    mutable int times_copy_assigned_from{};
    mutable int times_copy_constructed_from{};

    int times_move_assigned_into{};
    int times_move_assigned_from{};
    int times_move_constructed_from{};

    LifecycleTracker() : constructed_via{Constructor::default_} {}

    LifecycleTracker(LifecycleTracker const& that) : constructed_via{Constructor::copy}
    {
        ++that.times_copy_constructed_from;
    }
    LifecycleTracker& operator=(LifecycleTracker const& that)
    {
        ++times_copy_assigned_into;
        ++that.times_copy_assigned_from;
        return *this;
    }

    LifecycleTracker(LifecycleTracker&& that) noexcept : constructed_via{Constructor::move}
    {
        ++that.times_move_constructed_from;
    }
    LifecycleTracker& operator=(LifecycleTracker&& that) noexcept
    {
        ++times_move_assigned_into;
        ++that.times_move_assigned_from;
        return *this;
    }

    ~LifecycleTracker() { ++times_destructed; }

    bool moved_from() const { return times_move_assigned_from > 0 || times_move_constructed_from > 0; }
    bool moved_into() const { return times_move_assigned_into > 0 || constructed_via == Constructor::move; }
    bool copied_from() const { return times_copy_assigned_from > 0 || times_copy_constructed_from > 0; }
    bool copied_into() const { return times_copy_assigned_into > 0 || constructed_via == Constructor::copy; }
};

struct Tag0 { };
struct Tag1 { };
struct Tag2 { };
struct Tag3 { };
struct Tag4 { };
struct Tag5 { };
struct Tag6 { };
struct Tag7 { };
struct Tag8 { };
struct Tag9 { };
struct Tag10 { };
struct Tag11 { };
struct Tag12 { };
struct Tag13 { };
struct Tag14 { };
struct Tag15 { };
struct Tag16 { };
struct Tag17 { };
struct Tag18 { };
struct Tag19 { };
struct Tag20 { };
struct Tag21 { };
struct Tag22 { };
struct Tag23 { };
struct Tag24 { };
struct Tag25 { };
struct Tag26 { };
struct Tag27 { };
struct Tag28 { };
struct Tag29 { };
struct Tag30 { };
struct Tag31 { };
struct Tag32 { };

template <typename T>
struct Template {
    T x;
    T y;
};

struct NoDefaultCtor {
    NoDefaultCtor(int x) : x_(x) { }
    NoDefaultCtor(const NoDefaultCtor& obj) = default;
    NoDefaultCtor(NoDefaultCtor&& obj) = default;

    NoDefaultCtor& operator=(const NoDefaultCtor& obj) = default;
    NoDefaultCtor& operator=(NoDefaultCtor&& obj) = default;

    ~NoDefaultCtor() { }

    int x_;
};

struct DefaultInit {
    DefaultInit() : x_(99) { test_assert(y_ == 99); }
    DefaultInit(int x) : x_(x) { test_assert(y_ == 99); }
    DefaultInit(const DefaultInit& obj) = default;
    DefaultInit(DefaultInit&& obj) = default;

    DefaultInit& operator=(const DefaultInit& obj) = default;
    DefaultInit& operator=(DefaultInit&& obj) = default;

    ~DefaultInit() { }

    int x_;
    int y_ = 99;
};

struct NoCopy {
    NoCopy() : x_(99) { }
    NoCopy(int x) : x_(x) { }
    NoCopy(const NoCopy& obj) = delete;
    NoCopy(NoCopy&& obj) = default;

    NoCopy& operator=(const NoCopy& obj) = delete;
    NoCopy& operator=(NoCopy&& obj) = default;

    ~NoCopy() { }

    int x_;
};

struct NoMove {
    NoMove() : x_(99) { }
    NoMove(int x) : x_(x) { }
    NoMove(const NoMove& obj) = default;
    NoMove(NoMove&& obj) = delete;

    NoMove& operator=(const NoMove& obj) = default;
    NoMove& operator=(NoMove&& obj) = delete;

    ~NoMove() { }

    int x_;
};

struct NoCopyCtor {
    NoCopyCtor() : x_(99) { }
    NoCopyCtor(int x) : x_(x) { }
    NoCopyCtor(const NoCopyCtor& obj) = delete;
    NoCopyCtor(NoCopyCtor&& obj) = default;

    NoCopyCtor& operator=(const NoCopyCtor& obj) = default;
    NoCopyCtor& operator=(NoCopyCtor&& obj) = default;

    ~NoCopyCtor() { }

    int x_;
};

struct NoCopyAssign {
    NoCopyAssign() : x_(99) { }
    NoCopyAssign(int x) : x_(x) { }
    NoCopyAssign(const NoCopyAssign& obj) = default;
    NoCopyAssign(NoCopyAssign&& obj) = default;

    NoCopyAssign& operator=(const NoCopyAssign& obj) = delete;
    NoCopyAssign& operator=(NoCopyAssign&& obj) = default;

    ~NoCopyAssign() { }

    int x_;
};

struct NoMoveCtor {
    NoMoveCtor() : x_(99) { }
    NoMoveCtor(int x) : x_(x) { }
    NoMoveCtor(const NoMoveCtor& obj) = default;
    NoMoveCtor(NoMoveCtor&& obj) = delete;

    NoMoveCtor& operator=(const NoMoveCtor& obj) = default;
    NoMoveCtor& operator=(NoMoveCtor&& obj) = default;

    ~NoMoveCtor() { }

    int x_;
};

struct NoMoveAssign {
    NoMoveAssign() : x_(99) { }
    NoMoveAssign(int x) : x_(x) { }
    NoMoveAssign(const NoMoveAssign& obj) = default;
    NoMoveAssign(NoMoveAssign&& obj) = default;

    NoMoveAssign& operator=(const NoMoveAssign& obj) = default;
    NoMoveAssign& operator=(NoMoveAssign&& obj) = delete;

    ~NoMoveAssign() { }

    int x_;
};

struct NoDtor {
    NoDtor() : x_(99) { }
    NoDtor(int x) : x_(x) { }
    NoDtor(const NoDtor& obj) = default;
    NoDtor(NoDtor&& obj) = default;

    NoDtor& operator=(const NoDtor& obj) = delete;
    NoDtor& operator=(NoDtor&& obj) = default;

    ~NoDtor() = delete;

    int x_;
};

struct FlecsCtor {
    FlecsCtor(flecs::world&, flecs::entity e) : x_(89), e_(e) { }

    FlecsCtor(const FlecsCtor& obj) = delete;
    FlecsCtor(FlecsCtor&& obj) = default;

    FlecsCtor& operator=(const FlecsCtor& obj) = default;
    FlecsCtor& operator=(FlecsCtor&& obj) = default;

    ~FlecsCtor() { }

    int x_;
    flecs::entity e_;
};

struct FlecsCtorDefaultCtor {
    FlecsCtorDefaultCtor() : x_(99) { }
    FlecsCtorDefaultCtor(flecs::world&, flecs::entity e) : x_(89), e_(e) { }

    FlecsCtorDefaultCtor(const FlecsCtorDefaultCtor& obj) = delete;
    FlecsCtorDefaultCtor(FlecsCtorDefaultCtor&& obj) = default;

    FlecsCtorDefaultCtor& operator=(const FlecsCtorDefaultCtor& obj) = default;
    FlecsCtorDefaultCtor& operator=(FlecsCtorDefaultCtor&& obj) = default;

    ~FlecsCtorDefaultCtor() { }

    int x_;
    flecs::entity e_;
};

struct DefaultCtorValueCtor {
    DefaultCtorValueCtor() : x_(99) { }
    DefaultCtorValueCtor(int x) : x_(x) { }

    DefaultCtorValueCtor(const DefaultCtorValueCtor& obj) = delete;
    DefaultCtorValueCtor(DefaultCtorValueCtor&& obj) = default;

    DefaultCtorValueCtor& operator=(const DefaultCtorValueCtor& obj) = default;
    DefaultCtorValueCtor& operator=(DefaultCtorValueCtor&& obj) = default;

    ~DefaultCtorValueCtor() { }

    int x_;
};

struct FlecsCtorValueCtor {
    FlecsCtorValueCtor(int x) : x_(x) { }
    FlecsCtorValueCtor(flecs::world&, flecs::entity e) : x_(89), e_(e) { }

    FlecsCtorValueCtor(const FlecsCtorValueCtor& obj) = delete;
    FlecsCtorValueCtor(FlecsCtorValueCtor&& obj) = default;

    FlecsCtorValueCtor& operator=(const FlecsCtorValueCtor& obj) = default;
    FlecsCtorValueCtor& operator=(FlecsCtorValueCtor&& obj) = default;

    ~FlecsCtorValueCtor() { }

    int x_;
    flecs::entity e_;
};

class CountNoDefaultCtor {
public:
    CountNoDefaultCtor(int v) {
        ctor_invoked ++;
        value = v;
    }    

    ~CountNoDefaultCtor() {
        dtor_invoked ++;
    }

    CountNoDefaultCtor(const CountNoDefaultCtor& obj) {
        copy_ctor_invoked ++;
        this->value = obj.value;
    }

    CountNoDefaultCtor(CountNoDefaultCtor&& obj) noexcept {
        move_ctor_invoked ++;
        this->value = obj.value;
    }

    CountNoDefaultCtor& operator=(const CountNoDefaultCtor& obj) {
        copy_invoked ++;
        this->value = obj.value;
        return *this;
    }

    CountNoDefaultCtor& operator=(CountNoDefaultCtor&& obj) noexcept {
        move_invoked ++;
        this->value = obj.value;
        return *this;
    }

    static void reset() {
        ctor_invoked = 0;
        dtor_invoked = 0;
        copy_invoked = 0;
        move_invoked = 0;
        copy_ctor_invoked = 0;
        move_ctor_invoked = 0;
    }

    int value;

    static int ctor_invoked;
    static int dtor_invoked;
    static int copy_invoked;
    static int move_invoked;
    static int copy_ctor_invoked;
    static int move_ctor_invoked;
};

struct Struct_w_string {
    std::string value;
};

struct Struct_w_vector {
    std::vector<int> value;
};

void install_test_abort(void);

#endif

