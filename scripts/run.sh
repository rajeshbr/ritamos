#!/bin/bash

docker run \
    --rm \
    -it \
    -v $(pwd):/workspace \
    ritamos-dev
