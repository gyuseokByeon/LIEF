/* Copyright 2017 - 2022 R. Thomas
 * Copyright 2017 - 2022 Quarkslab
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <iostream>
#include <memory>

#include <LIEF/OAT.hpp>
#include <LIEF/logging.hpp>

using namespace LIEF::OAT;


int main(int argc, char **argv) {
  LIEF::logging::set_level(LIEF::logging::LOGGING_LEVEL::LOG_DEBUG);
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <OAT file>" << '\n';
    return EXIT_FAILURE;
  }

  std::unique_ptr<const Binary> binary;

  try {
    std::unique_ptr<const Binary> binary = LIEF::OAT::Parser::parse(argv[1]);
    std::cout << *binary << '\n';
  } catch (const LIEF::exception& e) {
    std::cerr << e.what() << '\n';
    return EXIT_FAILURE;
  }

}

