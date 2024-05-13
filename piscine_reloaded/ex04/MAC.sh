#!/bin/sh
ifconfig -a | grep -oiE '([a-z0-9]{2}:){5}..'
