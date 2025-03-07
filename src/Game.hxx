#ifndef GAME_HXX_
#define GAME_HXX_

#include "Scripting/ScriptEngine.hxx"
#include "engine/MessageQueue.hxx"
#include "util/Meta.hxx"
#ifdef USE_AUDIO
#include "services/AudioMixer.hxx"
#endif
#include "services/Randomizer.hxx"
#include "services/GameClock.hxx"
#include "services/ResourceManager.hxx"
#include "LOG.hxx"
#include "Exception.hxx"
#include "../game/GamePlay.hxx"

#include <thread>

using Thread = std::thread;
using RuntimeError = std::runtime_error;

namespace Cytopia
{
class Game
{
public:
  /**
   * @brief Creates a game
   * @details Initializes all GameServices and starts the threads
   */
  Game();

  /**
   * @brief Destroy a game
   */
  virtual ~Game() = default;

  /** @brief starts setting up the game
    * starts game initialization.
    */
  virtual void initialize();

  /** @brief begins the game
    * starts running the game
    * @param SkipMenu if the main menu should be skipped or not
    */
  virtual void run(bool SkipMenu = false);

  /** @brief ends the game
    * shuts down the game
    */
  virtual void shutdown();

private:
  void quit();
  bool m_shutDown = false;
};
} // namespace Cytopia
#endif
