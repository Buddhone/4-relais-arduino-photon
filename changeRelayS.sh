echo $1 echo $2

DEVICE_ID="2a0023001647343337363432"
TOKEN_ID="1d89ba47f0c5c9ee72b7ebb12ac171bf5c1f9234"

curl https://api.particle.io/v1/devices/$DEVICE_ID/changeRelayS \
     -d access_token=$TOKEN_ID \
     -d "args=$1,$2"
