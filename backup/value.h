#ifndef CC04EC7F_78DB_41C2_BCF6_B9527F3B8825
#define CC04EC7F_78DB_41C2_BCF6_B9527F3B8825

#ifndef _NNDEPLOY_BASE_VALUE_H_
#define _NNDEPLOY_BASE_VALUE_H_

#include "nndeploy/base/common.h"
#include "nndeploy/base/glic_stl_include.h"
#include "nndeploy/base/macro.h"
#include "nndeploy/base/status.h"

namespace nndeploy {
namespace base {

class NNDEPLOY_CC_API Value {
 public:
  Value() = default;
  Value(const Value& value) = default;
  Value(Value&& value) noexcept {
    data_type_ = value.data_type_;
    len_ = value.len_;
    internal_value_ = value.internal_value_;
  }

  // Value(uint8_t value) { set(value); }
  // Value(int8_t value) { set(value); }
  // Value(uint16_t value) { set(value); }
  // Value(int16_t value) { set(value); }
  // Value(uint32_t value) { set(value); }
  // Value(int32_t value) { set(value); }
  // Value(uint64_t value) { set(value); }
  // Value(int64_t value) { set(value); }
  // Value(float value) { set(value); }
  // Value(double value) { set(value); }
  template <typename T>
  Value(T value) {
    set(value);
  }

  // Value(uint8_t* value, int64_t len);
  // Value(int8_t* value, int64_t len);
  // Value(uint16_t* value, int64_t len);
  // Value(int16_t* value, int64_t len);
  // Value(uint32_t* value, int64_t len);
  // Value(int32_t* value, int64_t len);
  // Value(uint64_t* value, int64_t len);
  // Value(int64_t* value, int64_t len);
  // Value(float* value, int64_t len);
  // Value(double* value, int64_t len);
  template <typename T>
  Value(T* value, int64_t len) {
    set(value, len);
  }

  ~Value(){};

  Value& operator=(const Value& value) = default;
  Value& operator=(Value&& value) noexcept {
    data_type_ = value.data_type_;
    len_ = value.len_;
    internal_value_ = value.internal_value_;
    return *this;
  }

  // Value& operator=(uint8_t value);
  // Value& operator=(int8_t value);
  // Value& operator=(uint16_t value);
  // Value& operator=(int16_t value);
  // Value& operator=(uint32_t value);
  // Value& operator=(int32_t value);
  // Value& operator=(uint64_t value);
  // Value& operator=(int64_t value);
  // Value& operator=(float value);
  // Value& operator=(double value);
  // template <typename T>
  // Value& operator=(T value) {
  //   set(value);
  // }

  // void set(uint8_t value);
  // void set(int8_t value);
  // void set(uint16_t value);
  // void set(int16_t value);
  // void set(uint32_t value);
  // void set(int32_t value);
  // void set(uint64_t value);
  // void set(int64_t value);
  // void set(float value);
  // void set(double value);
  template <typename T>
  void set(T value);
  template <>
  void set<uint8_t>(T value) {
    data_type_ = dataTypeOf<uint8_t>();
    len_ = 1;
    internal_value_.uint8_value = value;
  }

  void set(uint8_t* value, int64_t len);
  void set(int8_t* value, int64_t len);
  void set(uint16_t* value, int64_t len);
  void set(int16_t* value, int64_t len);
  void set(uint32_t* value, int64_t len);
  void set(int32_t* value, int64_t len);
  void set(uint64_t* value, int64_t len);
  void set(int64_t* value, int64_t len);
  void set(float* value, int64_t len);
  void set(double* value, int64_t len);

  bool get(uint8_t& value);
  bool get(int8_t& value);
  bool get(uint16_t& value);
  bool get(int16_t& value);
  bool get(uint32_t& value);
  bool get(int32_t& value);
  bool get(uint64_t& value);
  bool get(int64_t& value);
  bool get(float& value);
  bool get(double& value);

  bool get(uint8_t** value);
  bool get(int8_t** value);
  bool get(uint16_t** value);
  bool get(int16_t** value);
  bool get(uint32_t** value);
  bool get(int32_t** value);
  bool get(uint64_t** value);
  bool get(int64_t** value);
  bool get(float** value);
  bool get(double** value);

  DataType getDataType() const;
  int64_t getLen() const;
  bool isValid() const;

 private:
  union InternalValue {
    uint8_t value_u8;
    int8_t value_i8;
    uint16_t value_u16;
    int16_t value_i16;
    uint32_t value_u32;
    int32_t value_i32;
    uint64_t value_u64;
    int64_t value_i64;
    size_t value_size;
    float value_f32;
    double value_f64;

    uint8_t* ptr_u8;
    int8_t* ptr_i8;
    uint16_t* ptr_u16;
    int16_t* ptr_i16;
    uint32_t* ptr_u32;
    int32_t* ptr_i32;
    uint64_t* ptr_u64;
    int64_t* ptr_i64;
    size_t* ptr_size;
    float* ptr_f32;
    double* ptr_f64;
    /**
     * @brief ptr_void is used to store the pointer of any type
     * data_type_.code_ = kDataTypeCodeOpaqueHandle
     * data_type_.bits_ = sizeof(any type)
     * data_type_.lanes_ = 1
     * len_ = len
     */
    void* ptr_void;
  };

  DataType data_type_;
  /**
   * @brief len_ is the length of the data
   * if the data is a pointer, len_ >= 1
   * if the data is a scalar, len_ == 0
   * if the data is invalid, len_ == -1
   */
  int64_t len_ = -1;
  InternalValue internal_value_;
};

}  // namespace base
}  // namespace nndeploy

#endif

#endif /* CC04EC7F_78DB_41C2_BCF6_B9527F3B8825 */
