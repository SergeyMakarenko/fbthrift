/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <iostream>
#include <memory>
#include <stdexcept>
#include <sstream>

#include <folly/init/Init.h>
#include <thrift/lib/cpp2/server/ThriftServer.h>

#include <thrift/tutorial/gen-cpp2/Calculator.h>

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::tutorial;

class CalculatorHandler : public CalculatorSvIf {
 public:
  CalculatorHandler() {}

  void ping() override {
    printf("ping()\n");
  }

  int32_t add(const int32_t n1, const int32_t n2) override {
    printf("add(%d,%d)\n", n1, n2);
    return n1 + n2;
  }

  int32_t calculate(const int32_t logid, const Work& work) override {
    printf("calculate(%d,{%d,%d,%d})\n",
           logid,
           static_cast<int32_t>(work.op),
           work.num1,
           work.num2);
    int32_t val;

    switch (work.op) {
    case Operation::ADD:
      val = work.num1 + work.num2;
      break;
    case Operation::SUBTRACT:
      val = work.num1 - work.num2;
      break;
    case Operation::MULTIPLY:
      val = work.num1 * work.num2;
      break;
    case Operation::DIVIDE:
      if (work.num2 == 0) {
        InvalidOperation io;
        io.op = work.op;
        io.why = "Cannot divide by 0";
        throw io;
      }
      val = work.num1 / work.num2;
      break;
    default:
      InvalidOperation io;
      io.op = work.op;
      io.why = "Invalid Operation";
      throw io;
    }

    SharedStruct ss;
    ss.key = logid;
    char buffer[12];
    snprintf(buffer, sizeof(buffer), "%d", val);
    ss.value = buffer;

    log[logid] = ss;

    return val;
  }

  void getStruct(SharedStruct& ret, const int32_t logid) override {
    printf("getStruct(%d)\n", logid);
    ret = log[logid];
  }

  void zip() override {
    printf("zip()\n");
  }

protected:
  map<int32_t, SharedStruct> log;

};

int main(int argc, char **argv) {
  folly::init(&argc, &argv, true);

  auto handler = make_shared<CalculatorHandler>();
  auto server = make_shared<ThriftServer>();
  server->setInterface(handler);
  server->setPort(9090);

  printf("Starting the server...\n");
  server->serve();
  printf("done.\n");
  return 0;
}
