#!/bin/bash

docker run \
  --privileged \
    --rm \
    -it \
    -v $(pwd):/workspace \
    ritamos-dev
