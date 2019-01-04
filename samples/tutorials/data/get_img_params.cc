// Copyright 2018 Slightech Co., Ltd. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include "mynteye/logger.h"
#include "mynteye/api/api.h"
#include "mynteye/types.h"

MYNTEYE_USE_NAMESPACE

int main(int argc, char *argv[]) {
  auto &&api = API::Create(argc, argv);
  if (!api) return 1;

  bool ok;
  auto &&request = api->SelectStreamRequest(&ok);
  if (!ok) return 1;
  api->ConfigStreamRequest(request);

  LOG(INFO) << "Intrinsics left: {" << api->GetIntrinsics(Stream::LEFT) << "}";
  LOG(INFO) << "Intrinsics right: {" << api->GetIntrinsics(Stream::RIGHT)
            << "}";
  LOG(INFO) << "Extrinsics right to left: {"
            << api->GetExtrinsics(Stream::RIGHT, Stream::LEFT) << "}";
  auto inr = api->GetIntrinsics(Stream::LEFT);
  // CameraParameters cmm(inr);
  // for (int i = 0;i< sizeof(cmm) ; i++) {
  //   printf(" %x ",cmm.raw[i]);
  // }
  // printf("end: %d\n", (int)(cmm.getModelType()));

  // Intrinsics2 xxx2;
  // CameraParameters cmm2(xxx2);
  // for (int i = 0;i< sizeof(cmm2) ; i++) {
  //   printf(" %x ",cmm2.raw[i]);
  // }
  // printf("end: %d\n", (int)(cmm2.getModelType()));

  // IntrinsicsBase xxx3;
  // CameraParameters cmm3(xxx3);
  // for (int i = 0;i< sizeof(cmm3) ; i++) {
  //   printf(" %x ",cmm3.raw[i]);
  // }
  // printf("end: %d\n", (int)(cmm3.getModelType()));

  api->GetIntrinsics<Intrinsics>(Stream::LEFT);

  return 0;
}
