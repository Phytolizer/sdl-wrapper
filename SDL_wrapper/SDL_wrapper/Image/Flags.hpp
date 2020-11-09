#pragma once

namespace sdl::Image
{

class InitFlag
{
  public:
    enum FlagT
    {
        none = 0,
        jpg,
        png,
        tif,
        webp,
    };

  private:
    FlagT m_f{none};

  public:
    // ReSharper disable once CppNonExplicitConvertingConstructor
    constexpr InitFlag(const FlagT f) : m_f(f)
    {
    }

    constexpr InitFlag operator|(const InitFlag &right) const noexcept
    {
        return InitFlag(static_cast<FlagT>(m_f | right.m_f));
    }

    explicit constexpr operator int() const
    {
        return static_cast<int>(m_f);
    }
};

constexpr InitFlag operator|(const InitFlag::FlagT left,
                             const InitFlag::FlagT right) noexcept
{
    return InitFlag(
        static_cast<InitFlag::FlagT>(static_cast<int>(left) | right));
}

} // namespace sdl::Image
