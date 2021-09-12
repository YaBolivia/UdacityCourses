#include <gazebo/gazebo.hh>

namespace gazebo
{
  class WorldPluginMyHumanoid : public WorldPlugin
  {
    public: WorldPluginMyHumanoid() : WorldPlugin()
            {
              printf("Welcome to Yann's world!\n");
            }

    public: void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
            {
            }
  };
  GZ_REGISTER_WORLD_PLUGIN(WorldPluginMyHumanoid)
}
