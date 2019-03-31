/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#include "timer.h"

namespace utils
{

void Timer::start()
{
    m_isStarted = true;
    m_startTicks = std::clock();
}

void Timer::clear()
{
    m_isStarted = false;
    m_isPaused = false;

    m_startTicks = 0;
    m_pausedTicks = 0;
}

void Timer::pause()
{
    if (m_isStarted && !m_isPaused)
    {
        m_isPaused = true;
        m_pausedTicks = std::clock() - m_startTicks;
        m_startTicks = 0;
    }
}

void Timer::restart()
{
    if (m_isStarted && m_isPaused)
    {
        m_isPaused = false;
        m_startTicks = std::clock() - m_pausedTicks;
        m_pausedTicks = 0;
    }
}

bool Timer::hasElapsed(clock_t ms) const
{
    if (getTicks() >= ms)
        return true;
    else return false;
}

clock_t Timer::getTicks() const
{
    if (!m_isStarted)
        return 0;
    if (m_isPaused)
        return m_pausedTicks;
    else
        return std::clock() - m_startTicks;
}

inline bool Timer::isStarted() const
{
    return m_isStarted;
}

inline bool Timer::isPaused() const
{
    return m_isPaused;
}

} // namespace utils