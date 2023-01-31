/**
 * @file device.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-11-24
 *
 * @copyright Copyright (c) 2022
 * @note ref opencv
 */
#ifndef _NNDEPLOY_INCLUDE_GRAPH_CONFIG_H_
#define _NNDEPLOY_INCLUDE_GRAPH_CONFIG_H_

#include "nndeploy/include/base/log.h"
#include "nndeploy/include/base/macro.h"
#include "nndeploy/include/base/object.h"
#include "nndeploy/include/base/status.h"
#include "nndeploy/include/base/basic.h"

namespace nndeploy {
namespace graph {

class Config {
 public:
 private:
  std::string name_;
};

}  // namespace graph
}  // namespace nndeploy

#endif