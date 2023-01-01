/**
 * @file engine.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef _NNDEPLOY_INCLUDE_GRAPH_ENGINE_H_
#define _NNDEPLOY_INCLUDE_GRAPH_ENGINE_H_

#include "nndeploy/include/base/log.h"
#include "nndeploy/include/base/macro.h"
#include "nndeploy/include/base/object.h"
#include "nndeploy/include/base/status.h"
#include "nndeploy/include/base/type.h"
#include "nndeploy/include/architecture/device.h"
#include "nndeploy/include/engine/config.h"
#include "nndeploy/include/engine/graph.h"
#include "nndeploy/include/engine/initializer.h"
#include "nndeploy/include/engine/io_array.h"
#include "nndeploy/include/engine/node.h"

namespace nndeploy {
namespace graph {

class Engine {
 public:
  explicit Engine();
  virtual ~Engine();

  virtual base::Status addDevice(const std::string &key,
                                 architecture::Device *device);
  virtual architecture::Device *getDevice(const std::string &key);

  virtual base::Status addNode(const std::string &key,
                               std::shared_ptr<Node> node);
  virtual base::Status getNode(const std::string &key,
                               std::shared_ptr<Node> node);

 private:
  std::map<std::string, std::shared_ptr<Node>> node_pool_;
  std::map<std::string, nndeploy::architecture::Device *> device_map_;
};

}  // namespace graph
}  // namespace nndeploy

#endif