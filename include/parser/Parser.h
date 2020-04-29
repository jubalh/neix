/**
 * Feed parser class.
 *
 * @package     CRSS
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2020, Thomas Schwarz
 * @license     -
 * @since       Version 0.1.0
 * @filesource
 */

#ifndef CRSS_PARSER_H
#define CRSS_PARSER_H

#include "rapidxml/rapidxml.hpp"
#include "feed/FeedLoader.h"

using namespace rapidxml;

namespace crss
{
    class Parser
    {
    public:
        Parser();
        ~Parser();

        void setRawRss(struct rawRss rawContent);
        struct rssItem* getFeedItem();

        char* convertHtmlToPlaintext(char *text);
        char* formatTimeString(const char *timeString);

    private:
        xml_document<> xmlDocument;
        xml_node<> *rootNode;
        xml_node<> *entryNode;
        struct rawRss *rss;
    };
}

#endif //CRSS_PARSER_H