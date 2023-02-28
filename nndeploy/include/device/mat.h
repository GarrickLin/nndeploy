/**
 * @file runtime.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-11-24
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef _NNDEPLOY_INCLUDE_DEVICE_MAT_H_
#define _NNDEPLOY_INCLUDE_DEVICE_MAT_H_

#include "nndeploy/include/base/basic.h"
#include "nndeploy/include/base/status.h"
#include "nndeploy/include/device/buffer.h"


namespace nndeploy {
namespace device {

class Device;

struct MatDesc {
  base::DataType data_type_;

  base::IntVector shape_;

  base::SizeVector stride_;
};

class Mat {
 public:
  Mat();
  virtual ~Mat();

  Mat(Device *device, int32_t height, int32_t width, int32_t channel,
      base::DataType data_type);
  Mat(Device *device, int32_t *shape, int32_t shape_len,
      base::DataType data_type);
  Mat(Device *device, base::IntVector shape_, base::DataType data_type);
  Mat(Device *device, MatDesc desc, base::IntVector config);

  Mat(BufferPool *buffer_pool, int32_t height, int32_t width, int32_t channel,
      base::DataType data_type);
  Mat(BufferPool *buffer_pool, int32_t *shape, int32_t shape_len,
      base::DataType data_type);
  Mat(BufferPool *buffer_pool, base::IntVector shape_, base::DataType data_type);
  Mat(BufferPool *buffer_pool, MatDesc desc, base::IntVector config);

  Mat(MatDesc desc, Buffer *buffer);

  //
  Mat(const Mat &mat);
  Mat(const Mat &&mat);

  //
  void operator=(const Mat &mat);
  void operator==(const Mat &&mat);

  // create
  void create(Device *device, MatDesc desc, base::IntVector config);
  void create(MatDesc desc, Buffer *buffer);

  // get
  bool empty();
  bool isContinue();

  MatDesc getDesc();
  base::DataType getDataType();
  base::IntVector getShape();
  int32_t getShapeIndex(int index);
  int32_t getHeight();
  int32_t getWidth();
  int32_t getChannel();
  base::SizeVector getStride();
  size_t getStrideIndex(int index);

  Buffer *getBuffer();
  base::DeviceType getDeviceType();
  Device *getDevice();
  BufferPool *getBufferPool();
  bool isBufferPool();
  bool isExternal();
  base::MemoryBufferType getMemoryBufferType();
  size_t getSize();
  base::SizeVector getSizeVector();
  base::IntVector getConfig();
  void *getPtr();
  int32_t getId();

 private:
  MatDesc desc;

  Buffer *buffer = nullptr;
};

}  // namespace device
}  // namespace nndeploy

#endif