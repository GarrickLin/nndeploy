
#include "nndeploy/inference/openvino/openvino_inference_param.h"

namespace nndeploy {
namespace inference {

static TypeInferenceParamRegister<
    TypeInferenceParamCreator<OpenVinoInferenceParam>>
    g_openvino_inference_param_register(base::kInferenceTypeOpenVino);

OpenVinoInferenceParam::OpenVinoInferenceParam() : InferenceParam() {}
OpenVinoInferenceParam::~OpenVinoInferenceParam() {}

base::Status OpenVinoInferenceParam::parse(const std::string &json,
                                           bool is_path) {
  base::Status status = InferenceParam::parse(json, is_path);
  if (status != base::kStatusCodeOk) {
    // TODO: log
    return status;
  }

  return base::kStatusCodeOk;
}

base::Status OpenVinoInferenceParam::set(const std::string &key,
                                         base::Value &value) {
  return base::kStatusCodeOk;
}

base::Status OpenVinoInferenceParam::get(const std::string &key,
                                         base::Value &value) {
  base::Status status = base::kStatusCodeOk;
  return base::kStatusCodeOk;
}

}  // namespace inference
}  // namespace nndeploy
