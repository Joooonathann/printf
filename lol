UIDQ="u-s4t2ud-de96ef3ddb5434e435bde5fc73cfc002330af60e16266331601e966957e54e0a"
SECRET="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"
TOKEN_ENDPOINT="https://api.intra.42.fr/oauth/token"
PARAMS="grant_type=client_credentials&client_id=$UIDQ&client_secret=$SECRET"
response=$(curl -s -X POST -d "$PARAMS" "$TOKEN_ENDPOINT")
access_token=$(echo "$response" | jq -r '.access_token')

if [ -z "$access_token" ]; then
    echo "Erreur lors de l'obtention du jeton d'accès"
    exit 1
fi

login="jalbiser"
endpoint="https://api.intra.42.fr/v2/users/$login"
infos=$(curl -s -H "Authorization: Bearer $access_token" "$endpoint")

if [ -z "$infos" ]; then
    echo "Erreur lors de la récupération des informations Jalbiser"
    exit 1
fi

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
CYAN='\033[0;36m'
BOLD='\033[1m'
NC='\033[0m'
BBLUE='\033[1;34m'

LEVEL=$(echo "$infos" | jq -r '.cursus_users[1].level')
subname=$(echo "$infos" | jq -r '.first_name')
name=$(echo "$infos" | jq -r '.last_name')
login=$(echo "$infos" | jq -r '.login')

LEVEL=$(echo "$infos" | jq -r '.cursus_users[1].level')
LEVEL_INT=${LEVEL%.*}
LEVEL_DECIMAL=${LEVEL#*.}
echo "
\t\t    ⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
\t\t    ⠀⠀⠀⡌⡀⠉⠓⢤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⠄⡄⠀
\t\t    ⠀⠀⠀⣇⢧⣶⡠⣬⣿⣶⣤⣤⣠⣴⣦⣤⣄⣀⠀⣀⣠⠞⢛⣡⣴⣾⣾⠀
\t\t    ⠀⠀⠀⠹⡜⣿⣿⣯⠻⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣩⣽⣿⡿⡽⠀
\t\t    ⠀⠀⠀⠀⢺⠄⡻⠀⠐⢻⣿⣿⣿⣿⠻⢻⠿⢻⣿⢿⣿⣿⣿⣿⡿⡕⠁⠀
\t\t    ⠀⠀⠀⠀⢨⡆⠁⠀⠀⠀⠀⣿⡟⠃⠀⠈⠀⠀⠈⠻⢻⣿⣿⠏⢠⠃⠀⠀
\t\t    ⠀⠀⠀⠀⢨⠃⠀⣀⣰⡄⢰⡿⠁⢠⣆⣀⠀⠀⠀⠀⠈⠻⢧⠀⢇⠀⠀⠀
\t\t    ⠀⠀⠀⠀⠞⠀⣼⣿⣾⡗⢸⠇⣰⣿⣿⣿⣿⣷⣤⠤⠀⢀⢈⠀⢸⡂⠀⠀
\t\t    ⠀⠈⠐⠤⠆⢼⣿⣿⠋⠀⠀⠀⠀⠻⣿⣿⣿⣿⣿⣿⣿⣚⣟⠀⠀⢳⡄⠀
\t\t    ⠀⠤⠤⢴⠧⣐⡺⢅⣤⣶⣶⡀⠀⠀⣻⣿⣿⠟⣻⣿⣿⡿⠷⢶⡀⠀⢻⠂
\t\t    ⠀⢈⡩⠿⢷⠒⠒⣺⣿⣿⣿⣧⣶⠠⠈⢨⣻⣿⡿⣿⣿⣿⡤⡄⢩⣬⡿⠆
\t\t    ⠈⠀⠀⠀⢚⡃⢀⣿⣿⣛⣿⣛⣻⣯⣽⣿⣿⣿⣿⣮⣿⣿⣿⣶⣦⣽⡍⠀
\t\t    ⠀⠀⠀⠀⢸⣅⢹⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⠻⠃⠀
\t\t    ⠀⠀⠀⠀⠈⠋⠘⠻⠋⢿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠟⠛⠛⠁⠁⠀⠀⠀⠀
\t\t    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
"
echo "\tWelcome $subname $name\t\t      \033[0m${BBLUE}$login${NC}"
echo "\tLevel $LEVEL_INT - $LEVEL_DECIMAL%"
echo "\t╔════════════════════════════════════════════════════╗"
echo -n "\t║ "
for ((i = 0; i < $LEVEL_DECIMAL / 2; i++)); do
    echo -n "█"
done
for ((j = 0; j < (50 - ($LEVEL_DECIMAL / 2)); j++)); do
    echo -n "▒"
done
echo -n " ║\n"
echo "\t╚════════════════════════════════════════════════════╝"
echo ""

