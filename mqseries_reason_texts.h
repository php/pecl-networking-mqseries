#ifdef MQRC_NONE
ADD_MQ_REASON_TXT(MQRC_NONE, "No reason to report."); /* 0 */
#endif /* MQRC_NONE */
#ifdef MQRC_APPL_FIRST
ADD_MQ_REASON_TXT(MQRC_APPL_FIRST, "Lowest value for an application-defined reason code returned by a data-conversion exit."); /* 900 */
#endif /* MQRC_APPL_FIRST */
#ifdef MQRC_APPL_LAST
ADD_MQ_REASON_TXT(MQRC_APPL_LAST, "Highest value for application-defined reason code returned by a data-conversion exit."); /* 999 */
#endif /* MQRC_APPL_LAST */
#ifdef MQRC_ALIAS_BASE_Q_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRC_ALIAS_BASE_Q_TYPE_ERROR, "Alias base queue not a valid type."); /* 2001 */
#endif /* MQRC_ALIAS_BASE_Q_TYPE_ERROR */
#ifdef MQRC_ALREADY_CONNECTED
ADD_MQ_REASON_TXT(MQRC_ALREADY_CONNECTED, "Application already connected."); /* 2002 */
#endif /* MQRC_ALREADY_CONNECTED */
#ifdef MQRC_BACKED_OUT
ADD_MQ_REASON_TXT(MQRC_BACKED_OUT, "Unit of work encountered fatal error or backed out."); /* 2003 */
#endif /* MQRC_BACKED_OUT */
#ifdef MQRC_BUFFER_ERROR
ADD_MQ_REASON_TXT(MQRC_BUFFER_ERROR, "Buffer parameter not valid."); /* 2004 */
#endif /* MQRC_BUFFER_ERROR */
#ifdef MQRC_BUFFER_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRC_BUFFER_LENGTH_ERROR, "Buffer length parameter not valid."); /* 2005 */
#endif /* MQRC_BUFFER_LENGTH_ERROR */
#ifdef MQRC_CHAR_ATTR_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRC_CHAR_ATTR_LENGTH_ERROR, "Length of character attributes not valid."); /* 2006 */
#endif /* MQRC_CHAR_ATTR_LENGTH_ERROR */
#ifdef MQRC_CHAR_ATTRS_ERROR
ADD_MQ_REASON_TXT(MQRC_CHAR_ATTRS_ERROR, "Character attributes string not valid."); /* 2007 */
#endif /* MQRC_CHAR_ATTRS_ERROR */
#ifdef MQRC_CHAR_ATTRS_TOO_SHORT
ADD_MQ_REASON_TXT(MQRC_CHAR_ATTRS_TOO_SHORT, "Not enough space allowed for character attributes."); /* 2008 */
#endif /* MQRC_CHAR_ATTRS_TOO_SHORT */
#ifdef MQRC_CONNECTION_BROKEN
ADD_MQ_REASON_TXT(MQRC_CONNECTION_BROKEN, "Connection to queue manager lost."); /* 2009 */
#endif /* MQRC_CONNECTION_BROKEN */
#ifdef MQRC_DATA_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRC_DATA_LENGTH_ERROR, "Data length parameter not valid."); /* 2010 */
#endif /* MQRC_DATA_LENGTH_ERROR */
#ifdef MQRC_DYNAMIC_Q_NAME_ERROR
ADD_MQ_REASON_TXT(MQRC_DYNAMIC_Q_NAME_ERROR, "Name of dynamic queue not valid."); /* 2011 */
#endif /* MQRC_DYNAMIC_Q_NAME_ERROR */
#ifdef MQRC_ENVIRONMENT_ERROR
ADD_MQ_REASON_TXT(MQRC_ENVIRONMENT_ERROR, "Call not valid in environment."); /* 2012 */
#endif /* MQRC_ENVIRONMENT_ERROR */
#ifdef MQRC_EXPIRY_ERROR
ADD_MQ_REASON_TXT(MQRC_EXPIRY_ERROR, "Expiry time not valid."); /* 2013 */
#endif /* MQRC_EXPIRY_ERROR */
#ifdef MQRC_FEEDBACK_ERROR
ADD_MQ_REASON_TXT(MQRC_FEEDBACK_ERROR, "Feedback code not valid."); /* 2014 */
#endif /* MQRC_FEEDBACK_ERROR */
#ifdef MQRC_GET_INHIBITED
ADD_MQ_REASON_TXT(MQRC_GET_INHIBITED, "Gets inhibited for the queue."); /* 2016 */
#endif /* MQRC_GET_INHIBITED */
#ifdef MQRC_HANDLE_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRC_HANDLE_NOT_AVAILABLE, "No more handles available."); /* 2017 */
#endif /* MQRC_HANDLE_NOT_AVAILABLE */
#ifdef MQRC_HCONN_ERROR
ADD_MQ_REASON_TXT(MQRC_HCONN_ERROR, "Connection handle not valid."); /* 2018 */
#endif /* MQRC_HCONN_ERROR */
#ifdef MQRC_HOBJ_ERROR
ADD_MQ_REASON_TXT(MQRC_HOBJ_ERROR, "Object handle not valid."); /* 2019 */
#endif /* MQRC_HOBJ_ERROR */
#ifdef MQRC_INHIBIT_VALUE_ERROR
ADD_MQ_REASON_TXT(MQRC_INHIBIT_VALUE_ERROR, "Value for inhibit-get or inhibit-put queue attribute not valid."); /* 2020 */
#endif /* MQRC_INHIBIT_VALUE_ERROR */
#ifdef MQRC_INT_ATTR_COUNT_ERROR
ADD_MQ_REASON_TXT(MQRC_INT_ATTR_COUNT_ERROR, "Count of integer attributes not valid."); /* 2021 */
#endif /* MQRC_INT_ATTR_COUNT_ERROR */
#ifdef MQRC_INT_ATTR_COUNT_TOO_SMALL
ADD_MQ_REASON_TXT(MQRC_INT_ATTR_COUNT_TOO_SMALL, "Not enough space allowed for integer attributes."); /* 2022 */
#endif /* MQRC_INT_ATTR_COUNT_TOO_SMALL */
#ifdef MQRC_INT_ATTRS_ARRAY_ERROR
ADD_MQ_REASON_TXT(MQRC_INT_ATTRS_ARRAY_ERROR, "Integer attributes array not valid."); /* 2023 */
#endif /* MQRC_INT_ATTRS_ARRAY_ERROR */
#ifdef MQRC_SYNCPOINT_LIMIT_REACHED
ADD_MQ_REASON_TXT(MQRC_SYNCPOINT_LIMIT_REACHED, "No more messages can be handled within current unit of work."); /* 2024 */
#endif /* MQRC_SYNCPOINT_LIMIT_REACHED */
#ifdef MQRC_MAX_CONNS_LIMIT_REACHED
ADD_MQ_REASON_TXT(MQRC_MAX_CONNS_LIMIT_REACHED, "Maximum number of connections reached."); /* 2025 */
#endif /* MQRC_MAX_CONNS_LIMIT_REACHED */
#ifdef MQRC_MD_ERROR
ADD_MQ_REASON_TXT(MQRC_MD_ERROR, "Message descriptor not valid."); /* 2026 */
#endif /* MQRC_MD_ERROR */
#ifdef MQRC_MISSING_REPLY_TO_Q
ADD_MQ_REASON_TXT(MQRC_MISSING_REPLY_TO_Q, "Missing reply-to queue."); /* 2027 */
#endif /* MQRC_MISSING_REPLY_TO_Q */
#ifdef MQRC_MSG_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRC_MSG_TYPE_ERROR, "Message type in message descriptor not valid."); /* 2029 */
#endif /* MQRC_MSG_TYPE_ERROR */
#ifdef MQRC_MSG_TOO_BIG_FOR_Q
ADD_MQ_REASON_TXT(MQRC_MSG_TOO_BIG_FOR_Q, "Message length greater than maximum for queue."); /* 2030 */
#endif /* MQRC_MSG_TOO_BIG_FOR_Q */
#ifdef MQRC_MSG_TOO_BIG_FOR_Q_MGR
ADD_MQ_REASON_TXT(MQRC_MSG_TOO_BIG_FOR_Q_MGR, "Message length greater than maximum for queue manager."); /* 2031 */
#endif /* MQRC_MSG_TOO_BIG_FOR_Q_MGR */
#ifdef MQRC_NO_MSG_AVAILABLE
ADD_MQ_REASON_TXT(MQRC_NO_MSG_AVAILABLE, "No message available."); /* 2033 */
#endif /* MQRC_NO_MSG_AVAILABLE */
#ifdef MQRC_NO_MSG_UNDER_CURSOR
ADD_MQ_REASON_TXT(MQRC_NO_MSG_UNDER_CURSOR, "Browse cursor not positioned on message."); /* 2034 */
#endif /* MQRC_NO_MSG_UNDER_CURSOR */
#ifdef MQRC_NOT_AUTHORIZED
ADD_MQ_REASON_TXT(MQRC_NOT_AUTHORIZED, "Not authorized for access."); /* 2035 */
#endif /* MQRC_NOT_AUTHORIZED */
#ifdef MQRC_NOT_OPEN_FOR_BROWSE
ADD_MQ_REASON_TXT(MQRC_NOT_OPEN_FOR_BROWSE, "Queue not open for browse."); /* 2036 */
#endif /* MQRC_NOT_OPEN_FOR_BROWSE */
#ifdef MQRC_NOT_OPEN_FOR_INPUT
ADD_MQ_REASON_TXT(MQRC_NOT_OPEN_FOR_INPUT, "Queue not open for input."); /* 2037 */
#endif /* MQRC_NOT_OPEN_FOR_INPUT */
#ifdef MQRC_NOT_OPEN_FOR_INQUIRE
ADD_MQ_REASON_TXT(MQRC_NOT_OPEN_FOR_INQUIRE, "Queue not open for inquire."); /* 2038 */
#endif /* MQRC_NOT_OPEN_FOR_INQUIRE */
#ifdef MQRC_NOT_OPEN_FOR_OUTPUT
ADD_MQ_REASON_TXT(MQRC_NOT_OPEN_FOR_OUTPUT, "Queue not open for output."); /* 2039 */
#endif /* MQRC_NOT_OPEN_FOR_OUTPUT */
#ifdef MQRC_NOT_OPEN_FOR_SET
ADD_MQ_REASON_TXT(MQRC_NOT_OPEN_FOR_SET, "Queue not open for set."); /* 2040 */
#endif /* MQRC_NOT_OPEN_FOR_SET */
#ifdef MQRC_OBJECT_CHANGED
ADD_MQ_REASON_TXT(MQRC_OBJECT_CHANGED, "Object definition changed since opened."); /* 2041 */
#endif /* MQRC_OBJECT_CHANGED */
#ifdef MQRC_OBJECT_IN_USE
ADD_MQ_REASON_TXT(MQRC_OBJECT_IN_USE, "Object already open with conflicting options."); /* 2042 */
#endif /* MQRC_OBJECT_IN_USE */
#ifdef MQRC_OBJECT_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRC_OBJECT_TYPE_ERROR, "Object type not valid."); /* 2043 */
#endif /* MQRC_OBJECT_TYPE_ERROR */
#ifdef MQRC_OD_ERROR
ADD_MQ_REASON_TXT(MQRC_OD_ERROR, "Object descriptor structure not valid."); /* 2044 */
#endif /* MQRC_OD_ERROR */
#ifdef MQRC_OPTION_NOT_VALID_FOR_TYPE
ADD_MQ_REASON_TXT(MQRC_OPTION_NOT_VALID_FOR_TYPE, "Option not valid for object type."); /* 2045 */
#endif /* MQRC_OPTION_NOT_VALID_FOR_TYPE */
#ifdef MQRC_OPTIONS_ERROR
ADD_MQ_REASON_TXT(MQRC_OPTIONS_ERROR, "Options not valid or not consistent."); /* 2046 */
#endif /* MQRC_OPTIONS_ERROR */
#ifdef MQRC_PERSISTENCE_ERROR
ADD_MQ_REASON_TXT(MQRC_PERSISTENCE_ERROR, "Persistence not valid."); /* 2047 */
#endif /* MQRC_PERSISTENCE_ERROR */
#ifdef MQRC_PERSISTENT_NOT_ALLOWED
ADD_MQ_REASON_TXT(MQRC_PERSISTENT_NOT_ALLOWED, "Message on a temporary dynamic queue cannot be persistent."); /* 2048 */
#endif /* MQRC_PERSISTENT_NOT_ALLOWED */
#ifdef MQRC_PRIORITY_EXCEEDS_MAXIMUM
ADD_MQ_REASON_TXT(MQRC_PRIORITY_EXCEEDS_MAXIMUM, "Message Priority exceeds maximum value supported."); /* 2049 */
#endif /* MQRC_PRIORITY_EXCEEDS_MAXIMUM */
#ifdef MQRC_PRIORITY_ERROR
ADD_MQ_REASON_TXT(MQRC_PRIORITY_ERROR, "Message priority not valid."); /* 2050 */
#endif /* MQRC_PRIORITY_ERROR */
#ifdef MQRC_PUT_INHIBITED
ADD_MQ_REASON_TXT(MQRC_PUT_INHIBITED, "Put calls inhibited for the queue."); /* 2051 */
#endif /* MQRC_PUT_INHIBITED */
#ifdef MQRC_Q_DELETED
ADD_MQ_REASON_TXT(MQRC_Q_DELETED, "Queue has been deleted."); /* 2052 */
#endif /* MQRC_Q_DELETED */
#ifdef MQRC_Q_FULL
ADD_MQ_REASON_TXT(MQRC_Q_FULL, "Queue already contains maximum number of messages."); /* 2053 */
#endif /* MQRC_Q_FULL */
#ifdef MQRC_Q_NOT_EMPTY
ADD_MQ_REASON_TXT(MQRC_Q_NOT_EMPTY, "Queue contains one or more messages or uncommitted put or get requests."); /* 2055 */
#endif /* MQRC_Q_NOT_EMPTY */
#ifdef MQRC_Q_SPACE_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRC_Q_SPACE_NOT_AVAILABLE, "No space available on disk for queue."); /* 2056 */
#endif /* MQRC_Q_SPACE_NOT_AVAILABLE */
#ifdef MQRC_Q_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRC_Q_TYPE_ERROR, "Queue type not valid."); /* 2057 */
#endif /* MQRC_Q_TYPE_ERROR */
#ifdef MQRC_Q_MGR_NAME_ERROR
ADD_MQ_REASON_TXT(MQRC_Q_MGR_NAME_ERROR, "Queue manager name not valid or not known."); /* 2058 */
#endif /* MQRC_Q_MGR_NAME_ERROR */
#ifdef MQRC_Q_MGR_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRC_Q_MGR_NOT_AVAILABLE, "Queue manager not available for connection."); /* 2059 */
#endif /* MQRC_Q_MGR_NOT_AVAILABLE */
#ifdef MQRC_REPORT_OPTIONS_ERROR
ADD_MQ_REASON_TXT(MQRC_REPORT_OPTIONS_ERROR, "Report options in message descriptor not valid."); /* 2061 */
#endif /* MQRC_REPORT_OPTIONS_ERROR */
#ifdef MQRC_SECOND_MARK_NOT_ALLOWED
ADD_MQ_REASON_TXT(MQRC_SECOND_MARK_NOT_ALLOWED, "A message is already marked."); /* 2062 */
#endif /* MQRC_SECOND_MARK_NOT_ALLOWED */
#ifdef MQRC_SECURITY_ERROR
ADD_MQ_REASON_TXT(MQRC_SECURITY_ERROR, "Security error occurred."); /* 2063 */
#endif /* MQRC_SECURITY_ERROR */
#ifdef MQRC_SELECTOR_COUNT_ERROR
ADD_MQ_REASON_TXT(MQRC_SELECTOR_COUNT_ERROR, "Count of selectors not valid."); /* 2065 */
#endif /* MQRC_SELECTOR_COUNT_ERROR */
#ifdef MQRC_SELECTOR_LIMIT_EXCEEDED
ADD_MQ_REASON_TXT(MQRC_SELECTOR_LIMIT_EXCEEDED, "Count of selectors too big."); /* 2066 */
#endif /* MQRC_SELECTOR_LIMIT_EXCEEDED */
#ifdef MQRC_SELECTOR_ERROR
ADD_MQ_REASON_TXT(MQRC_SELECTOR_ERROR, "Attribute selector not valid."); /* 2067 */
#endif /* MQRC_SELECTOR_ERROR */
#ifdef MQRC_SELECTOR_NOT_FOR_TYPE
ADD_MQ_REASON_TXT(MQRC_SELECTOR_NOT_FOR_TYPE, "Selector not applicable to queue type."); /* 2068 */
#endif /* MQRC_SELECTOR_NOT_FOR_TYPE */
#ifdef MQRC_SIGNAL_OUTSTANDING
ADD_MQ_REASON_TXT(MQRC_SIGNAL_OUTSTANDING, "Signal outstanding for this handle."); /* 2069 */
#endif /* MQRC_SIGNAL_OUTSTANDING */
#ifdef MQRC_SIGNAL_REQUEST_ACCEPTED
ADD_MQ_REASON_TXT(MQRC_SIGNAL_REQUEST_ACCEPTED, "No message returned (but signal request accepted)."); /* 2070 */
#endif /* MQRC_SIGNAL_REQUEST_ACCEPTED */
#ifdef MQRC_STORAGE_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRC_STORAGE_NOT_AVAILABLE, "Insufficient storage available."); /* 2071 */
#endif /* MQRC_STORAGE_NOT_AVAILABLE */
#ifdef MQRC_SYNCPOINT_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRC_SYNCPOINT_NOT_AVAILABLE, "Syncpoint support not available."); /* 2072 */
#endif /* MQRC_SYNCPOINT_NOT_AVAILABLE */
#ifdef MQRC_TRIGGER_CONTROL_ERROR
ADD_MQ_REASON_TXT(MQRC_TRIGGER_CONTROL_ERROR, "Value for trigger-control attribute not valid."); /* 2075 */
#endif /* MQRC_TRIGGER_CONTROL_ERROR */
#ifdef MQRC_TRIGGER_DEPTH_ERROR
ADD_MQ_REASON_TXT(MQRC_TRIGGER_DEPTH_ERROR, "Value for trigger-depth attribute not valid."); /* 2076 */
#endif /* MQRC_TRIGGER_DEPTH_ERROR */
#ifdef MQRC_TRIGGER_MSG_PRIORITY_ERR
ADD_MQ_REASON_TXT(MQRC_TRIGGER_MSG_PRIORITY_ERR, "Value for trigger-message-priority attribute not valid."); /* 2077 */
#endif /* MQRC_TRIGGER_MSG_PRIORITY_ERR */
#ifdef MQRC_TRIGGER_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRC_TRIGGER_TYPE_ERROR, "Value for trigger-type attribute not valid."); /* 2078 */
#endif /* MQRC_TRIGGER_TYPE_ERROR */
#ifdef MQRC_TRUNCATED_MSG_ACCEPTED
ADD_MQ_REASON_TXT(MQRC_TRUNCATED_MSG_ACCEPTED, "Truncated message returned (processing completed)."); /* 2079 */
#endif /* MQRC_TRUNCATED_MSG_ACCEPTED */
#ifdef MQRC_TRUNCATED_MSG_FAILED
ADD_MQ_REASON_TXT(MQRC_TRUNCATED_MSG_FAILED, "Truncated message returned (processing not completed)."); /* 2080 */
#endif /* MQRC_TRUNCATED_MSG_FAILED */
#ifdef MQRC_UNKNOWN_ALIAS_BASE_Q
ADD_MQ_REASON_TXT(MQRC_UNKNOWN_ALIAS_BASE_Q, "Unknown alias base queue."); /* 2082 */
#endif /* MQRC_UNKNOWN_ALIAS_BASE_Q */
#ifdef MQRC_UNKNOWN_OBJECT_NAME
ADD_MQ_REASON_TXT(MQRC_UNKNOWN_OBJECT_NAME, "Unknown object name."); /* 2085 */
#endif /* MQRC_UNKNOWN_OBJECT_NAME */
#ifdef MQRC_UNKNOWN_OBJECT_Q_MGR
ADD_MQ_REASON_TXT(MQRC_UNKNOWN_OBJECT_Q_MGR, "Unknown object queue manager."); /* 2086 */
#endif /* MQRC_UNKNOWN_OBJECT_Q_MGR */
#ifdef MQRC_UNKNOWN_REMOTE_Q_MGR
ADD_MQ_REASON_TXT(MQRC_UNKNOWN_REMOTE_Q_MGR, "Unknown remote queue manager."); /* 2087 */
#endif /* MQRC_UNKNOWN_REMOTE_Q_MGR */
#ifdef MQRC_WAIT_INTERVAL_ERROR
ADD_MQ_REASON_TXT(MQRC_WAIT_INTERVAL_ERROR, "Wait interval in MQGMO not valid."); /* 2090 */
#endif /* MQRC_WAIT_INTERVAL_ERROR */
#ifdef MQRC_XMIT_Q_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRC_XMIT_Q_TYPE_ERROR, "Transmission queue not local."); /* 2091 */
#endif /* MQRC_XMIT_Q_TYPE_ERROR */
#ifdef MQRC_XMIT_Q_USAGE_ERROR
ADD_MQ_REASON_TXT(MQRC_XMIT_Q_USAGE_ERROR, "Transmission queue with wrong usage."); /* 2092 */
#endif /* MQRC_XMIT_Q_USAGE_ERROR */
#ifdef MQRC_NOT_OPEN_FOR_PASS_ALL
ADD_MQ_REASON_TXT(MQRC_NOT_OPEN_FOR_PASS_ALL, "Queue not open for pass all context."); /* 2093 */
#endif /* MQRC_NOT_OPEN_FOR_PASS_ALL */
#ifdef MQRC_NOT_OPEN_FOR_PASS_IDENT
ADD_MQ_REASON_TXT(MQRC_NOT_OPEN_FOR_PASS_IDENT, "Queue not open for pass identity context."); /* 2094 */
#endif /* MQRC_NOT_OPEN_FOR_PASS_IDENT */
#ifdef MQRC_NOT_OPEN_FOR_SET_ALL
ADD_MQ_REASON_TXT(MQRC_NOT_OPEN_FOR_SET_ALL, "Queue not open for set all context."); /* 2095 */
#endif /* MQRC_NOT_OPEN_FOR_SET_ALL */
#ifdef MQRC_NOT_OPEN_FOR_SET_IDENT
ADD_MQ_REASON_TXT(MQRC_NOT_OPEN_FOR_SET_IDENT, "Queue not open for set identity context."); /* 2096 */
#endif /* MQRC_NOT_OPEN_FOR_SET_IDENT */
#ifdef MQRC_CONTEXT_HANDLE_ERROR
ADD_MQ_REASON_TXT(MQRC_CONTEXT_HANDLE_ERROR, "Queue handle referred to does not save context."); /* 2097 */
#endif /* MQRC_CONTEXT_HANDLE_ERROR */
#ifdef MQRC_CONTEXT_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRC_CONTEXT_NOT_AVAILABLE, "Context not available for queue handle referred to."); /* 2098 */
#endif /* MQRC_CONTEXT_NOT_AVAILABLE */
#ifdef MQRC_SIGNAL1_ERROR
ADD_MQ_REASON_TXT(MQRC_SIGNAL1_ERROR, "Signal field not valid."); /* 2099 */
#endif /* MQRC_SIGNAL1_ERROR */
#ifdef MQRC_OBJECT_ALREADY_EXISTS
ADD_MQ_REASON_TXT(MQRC_OBJECT_ALREADY_EXISTS, "Object already exists."); /* 2100 */
#endif /* MQRC_OBJECT_ALREADY_EXISTS */
#ifdef MQRC_OBJECT_DAMAGED
ADD_MQ_REASON_TXT(MQRC_OBJECT_DAMAGED, "Object damaged."); /* 2101 */
#endif /* MQRC_OBJECT_DAMAGED */
#ifdef MQRC_RESOURCE_PROBLEM
ADD_MQ_REASON_TXT(MQRC_RESOURCE_PROBLEM, "Insufficient system resources available."); /* 2102 */
#endif /* MQRC_RESOURCE_PROBLEM */
#ifdef MQRC_ANOTHER_Q_MGR_CONNECTED
ADD_MQ_REASON_TXT(MQRC_ANOTHER_Q_MGR_CONNECTED, "Another queue manager already connected."); /* 2103 */
#endif /* MQRC_ANOTHER_Q_MGR_CONNECTED */
#ifdef MQRC_UNKNOWN_REPORT_OPTION
ADD_MQ_REASON_TXT(MQRC_UNKNOWN_REPORT_OPTION, "Report option(s) in message descriptor not recognized."); /* 2104 */
#endif /* MQRC_UNKNOWN_REPORT_OPTION */
#ifdef MQRC_STORAGE_CLASS_ERROR
ADD_MQ_REASON_TXT(MQRC_STORAGE_CLASS_ERROR, "Storage class error."); /* 2105 */
#endif /* MQRC_STORAGE_CLASS_ERROR */
#ifdef MQRC_COD_NOT_VALID_FOR_XCF_Q
ADD_MQ_REASON_TXT(MQRC_COD_NOT_VALID_FOR_XCF_Q, "COD report option not valid for XCF queue."); /* 2106 */
#endif /* MQRC_COD_NOT_VALID_FOR_XCF_Q */
#ifdef MQRC_XWAIT_CANCELED
ADD_MQ_REASON_TXT(MQRC_XWAIT_CANCELED, "MQXWAIT call canceled."); /* 2107 */
#endif /* MQRC_XWAIT_CANCELED */
#ifdef MQRC_XWAIT_ERROR
ADD_MQ_REASON_TXT(MQRC_XWAIT_ERROR, "Invocation of MQXWAIT call not valid."); /* 2108 */
#endif /* MQRC_XWAIT_ERROR */
#ifdef MQRC_SUPPRESSED_BY_EXIT
ADD_MQ_REASON_TXT(MQRC_SUPPRESSED_BY_EXIT, "Call suppressed by exit program."); /* 2109 */
#endif /* MQRC_SUPPRESSED_BY_EXIT */
#ifdef MQRC_FORMAT_ERROR
ADD_MQ_REASON_TXT(MQRC_FORMAT_ERROR, "Message format not valid."); /* 2110 */
#endif /* MQRC_FORMAT_ERROR */
#ifdef MQRC_SOURCE_CCSID_ERROR
ADD_MQ_REASON_TXT(MQRC_SOURCE_CCSID_ERROR, "Source coded character set identifier not valid."); /* 2111 */
#endif /* MQRC_SOURCE_CCSID_ERROR */
#ifdef MQRC_SOURCE_INTEGER_ENC_ERROR
ADD_MQ_REASON_TXT(MQRC_SOURCE_INTEGER_ENC_ERROR, "Source integer encoding not recognized."); /* 2112 */
#endif /* MQRC_SOURCE_INTEGER_ENC_ERROR */
#ifdef MQRC_SOURCE_DECIMAL_ENC_ERROR
ADD_MQ_REASON_TXT(MQRC_SOURCE_DECIMAL_ENC_ERROR, "Packed-decimal encoding in message not recognized."); /* 2113 */
#endif /* MQRC_SOURCE_DECIMAL_ENC_ERROR */
#ifdef MQRC_SOURCE_FLOAT_ENC_ERROR
ADD_MQ_REASON_TXT(MQRC_SOURCE_FLOAT_ENC_ERROR, "Floating-point encoding in message not recognized."); /* 2114 */
#endif /* MQRC_SOURCE_FLOAT_ENC_ERROR */
#ifdef MQRC_TARGET_CCSID_ERROR
ADD_MQ_REASON_TXT(MQRC_TARGET_CCSID_ERROR, "Target coded character set identifier not valid."); /* 2115 */
#endif /* MQRC_TARGET_CCSID_ERROR */
#ifdef MQRC_TARGET_INTEGER_ENC_ERROR
ADD_MQ_REASON_TXT(MQRC_TARGET_INTEGER_ENC_ERROR, "Target integer encoding not recognized."); /* 2116 */
#endif /* MQRC_TARGET_INTEGER_ENC_ERROR */
#ifdef MQRC_TARGET_DECIMAL_ENC_ERROR
ADD_MQ_REASON_TXT(MQRC_TARGET_DECIMAL_ENC_ERROR, "Packed-decimal encoding specified by receiver not recognized."); /* 2117 */
#endif /* MQRC_TARGET_DECIMAL_ENC_ERROR */
#ifdef MQRC_TARGET_FLOAT_ENC_ERROR
ADD_MQ_REASON_TXT(MQRC_TARGET_FLOAT_ENC_ERROR, "Floating-point encoding specified by receiver not recognized."); /* 2118 */
#endif /* MQRC_TARGET_FLOAT_ENC_ERROR */
#ifdef MQRC_NOT_CONVERTED
ADD_MQ_REASON_TXT(MQRC_NOT_CONVERTED, "Application message data not converted."); /* 2119 */
#endif /* MQRC_NOT_CONVERTED */
#ifdef MQRC_CONVERTED_MSG_TOO_BIG
ADD_MQ_REASON_TXT(MQRC_CONVERTED_MSG_TOO_BIG, "Converted data too big for buffer."); /* 2120 */
#endif /* MQRC_CONVERTED_MSG_TOO_BIG */
#ifdef MQRC_NO_EXTERNAL_PARTICIPANTS
ADD_MQ_REASON_TXT(MQRC_NO_EXTERNAL_PARTICIPANTS, "No participating resource managers registered."); /* 2121 */
#endif /* MQRC_NO_EXTERNAL_PARTICIPANTS */
#ifdef MQRC_PARTICIPANT_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRC_PARTICIPANT_NOT_AVAILABLE, "Participating resource manager not available."); /* 2122 */
#endif /* MQRC_PARTICIPANT_NOT_AVAILABLE */
#ifdef MQRC_OUTCOME_MIXED
ADD_MQ_REASON_TXT(MQRC_OUTCOME_MIXED, "Result of commit or back-out operation is mixed."); /* 2123 */
#endif /* MQRC_OUTCOME_MIXED */
#ifdef MQRC_OUTCOME_PENDING
ADD_MQ_REASON_TXT(MQRC_OUTCOME_PENDING, "Result of commit operation is pending."); /* 2124 */
#endif /* MQRC_OUTCOME_PENDING */
#ifdef MQRC_BRIDGE_STARTED
ADD_MQ_REASON_TXT(MQRC_BRIDGE_STARTED, "Bridge started."); /* 2125 */
#endif /* MQRC_BRIDGE_STARTED */
#ifdef MQRC_BRIDGE_STOPPED
ADD_MQ_REASON_TXT(MQRC_BRIDGE_STOPPED, "Bridge stopped."); /* 2126 */
#endif /* MQRC_BRIDGE_STOPPED */
#ifdef MQRC_ADAPTER_STORAGE_SHORTAGE
ADD_MQ_REASON_TXT(MQRC_ADAPTER_STORAGE_SHORTAGE, "Insufficient storage for adapter."); /* 2127 */
#endif /* MQRC_ADAPTER_STORAGE_SHORTAGE */
#ifdef MQRC_UOW_IN_PROGRESS
ADD_MQ_REASON_TXT(MQRC_UOW_IN_PROGRESS, "Unit of work already started."); /* 2128 */
#endif /* MQRC_UOW_IN_PROGRESS */
#ifdef MQRC_ADAPTER_CONN_LOAD_ERROR
ADD_MQ_REASON_TXT(MQRC_ADAPTER_CONN_LOAD_ERROR, "Unable to load adapter connection module."); /* 2129 */
#endif /* MQRC_ADAPTER_CONN_LOAD_ERROR */
#ifdef MQRC_ADAPTER_SERV_LOAD_ERROR
ADD_MQ_REASON_TXT(MQRC_ADAPTER_SERV_LOAD_ERROR, "Unable to load adapter service module."); /* 2130 */
#endif /* MQRC_ADAPTER_SERV_LOAD_ERROR */
#ifdef MQRC_ADAPTER_DEFS_ERROR
ADD_MQ_REASON_TXT(MQRC_ADAPTER_DEFS_ERROR, "Adapter subsystem definition module not valid."); /* 2131 */
#endif /* MQRC_ADAPTER_DEFS_ERROR */
#ifdef MQRC_ADAPTER_DEFS_LOAD_ERROR
ADD_MQ_REASON_TXT(MQRC_ADAPTER_DEFS_LOAD_ERROR, "Unable to load adapter subsystem definition module."); /* 2132 */
#endif /* MQRC_ADAPTER_DEFS_LOAD_ERROR */
#ifdef MQRC_ADAPTER_CONV_LOAD_ERROR
ADD_MQ_REASON_TXT(MQRC_ADAPTER_CONV_LOAD_ERROR, "Unable to load data conversion services modules."); /* 2133 */
#endif /* MQRC_ADAPTER_CONV_LOAD_ERROR */
#ifdef MQRC_BO_ERROR
ADD_MQ_REASON_TXT(MQRC_BO_ERROR, "Begin-options structure not valid."); /* 2134 */
#endif /* MQRC_BO_ERROR */
#ifdef MQRC_DH_ERROR
ADD_MQ_REASON_TXT(MQRC_DH_ERROR, "Distribution header structure not valid."); /* 2135 */
#endif /* MQRC_DH_ERROR */
#ifdef MQRC_MULTIPLE_REASONS
ADD_MQ_REASON_TXT(MQRC_MULTIPLE_REASONS, "Multiple reason codes returned."); /* 2136 */
#endif /* MQRC_MULTIPLE_REASONS */
#ifdef MQRC_OPEN_FAILED
ADD_MQ_REASON_TXT(MQRC_OPEN_FAILED, "Object not opened successfully."); /* 2137 */
#endif /* MQRC_OPEN_FAILED */
#ifdef MQRC_ADAPTER_DISC_LOAD_ERROR
ADD_MQ_REASON_TXT(MQRC_ADAPTER_DISC_LOAD_ERROR, "Unable to load adapter disconnection module."); /* 2138 */
#endif /* MQRC_ADAPTER_DISC_LOAD_ERROR */
#ifdef MQRC_CNO_ERROR
ADD_MQ_REASON_TXT(MQRC_CNO_ERROR, "Connect-options structure not valid."); /* 2139 */
#endif /* MQRC_CNO_ERROR */
#ifdef MQRC_CICS_WAIT_FAILED
ADD_MQ_REASON_TXT(MQRC_CICS_WAIT_FAILED, "Wait request rejected by CICS."); /* 2140 */
#endif /* MQRC_CICS_WAIT_FAILED */
#ifdef MQRC_DLH_ERROR
ADD_MQ_REASON_TXT(MQRC_DLH_ERROR, "Dead letter header structure not valid."); /* 2141 */
#endif /* MQRC_DLH_ERROR */
#ifdef MQRC_HEADER_ERROR
ADD_MQ_REASON_TXT(MQRC_HEADER_ERROR, "MQ header structure not valid."); /* 2142 */
#endif /* MQRC_HEADER_ERROR */
#ifdef MQRC_SOURCE_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRC_SOURCE_LENGTH_ERROR, "Source length parameter not valid."); /* 2143 */
#endif /* MQRC_SOURCE_LENGTH_ERROR */
#ifdef MQRC_TARGET_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRC_TARGET_LENGTH_ERROR, "Target length parameter not valid."); /* 2144 */
#endif /* MQRC_TARGET_LENGTH_ERROR */
#ifdef MQRC_SOURCE_BUFFER_ERROR
ADD_MQ_REASON_TXT(MQRC_SOURCE_BUFFER_ERROR, "Source buffer parameter not valid."); /* 2145 */
#endif /* MQRC_SOURCE_BUFFER_ERROR */
#ifdef MQRC_TARGET_BUFFER_ERROR
ADD_MQ_REASON_TXT(MQRC_TARGET_BUFFER_ERROR, "Target buffer parameter not valid."); /* 2146 */
#endif /* MQRC_TARGET_BUFFER_ERROR */
#ifdef MQRC_IIH_ERROR
ADD_MQ_REASON_TXT(MQRC_IIH_ERROR, "IMS information header structure not valid."); /* 2148 */
#endif /* MQRC_IIH_ERROR */
#ifdef MQRC_PCF_ERROR
ADD_MQ_REASON_TXT(MQRC_PCF_ERROR, "PCF structures not valid."); /* 2149 */
#endif /* MQRC_PCF_ERROR */
#ifdef MQRC_DBCS_ERROR
ADD_MQ_REASON_TXT(MQRC_DBCS_ERROR, "DBCS string not valid."); /* 2150 */
#endif /* MQRC_DBCS_ERROR */
#ifdef MQRC_OBJECT_NAME_ERROR
ADD_MQ_REASON_TXT(MQRC_OBJECT_NAME_ERROR, "Object name not valid."); /* 2152 */
#endif /* MQRC_OBJECT_NAME_ERROR */
#ifdef MQRC_OBJECT_Q_MGR_NAME_ERROR
ADD_MQ_REASON_TXT(MQRC_OBJECT_Q_MGR_NAME_ERROR, "Object queue-manager name not valid."); /* 2153 */
#endif /* MQRC_OBJECT_Q_MGR_NAME_ERROR */
#ifdef MQRC_RECS_PRESENT_ERROR
ADD_MQ_REASON_TXT(MQRC_RECS_PRESENT_ERROR, "Number of records present not valid."); /* 2154 */
#endif /* MQRC_RECS_PRESENT_ERROR */
#ifdef MQRC_OBJECT_RECORDS_ERROR
ADD_MQ_REASON_TXT(MQRC_OBJECT_RECORDS_ERROR, "Object records not valid."); /* 2155 */
#endif /* MQRC_OBJECT_RECORDS_ERROR */
#ifdef MQRC_RESPONSE_RECORDS_ERROR
ADD_MQ_REASON_TXT(MQRC_RESPONSE_RECORDS_ERROR, "Response records not valid."); /* 2156 */
#endif /* MQRC_RESPONSE_RECORDS_ERROR */
#ifdef MQRC_ASID_MISMATCH
ADD_MQ_REASON_TXT(MQRC_ASID_MISMATCH, "Primary and home ASIDs differ."); /* 2157 */
#endif /* MQRC_ASID_MISMATCH */
#ifdef MQRC_PMO_RECORD_FLAGS_ERROR
ADD_MQ_REASON_TXT(MQRC_PMO_RECORD_FLAGS_ERROR, "Put message record flags not valid."); /* 2158 */
#endif /* MQRC_PMO_RECORD_FLAGS_ERROR */
#ifdef MQRC_PUT_MSG_RECORDS_ERROR
ADD_MQ_REASON_TXT(MQRC_PUT_MSG_RECORDS_ERROR, "Put message records not valid."); /* 2159 */
#endif /* MQRC_PUT_MSG_RECORDS_ERROR */
#ifdef MQRC_CONN_ID_IN_USE
ADD_MQ_REASON_TXT(MQRC_CONN_ID_IN_USE, "Connection identifier already in use."); /* 2160 */
#endif /* MQRC_CONN_ID_IN_USE */
#ifdef MQRC_Q_MGR_QUIESCING
ADD_MQ_REASON_TXT(MQRC_Q_MGR_QUIESCING, "Queue manager quiescing."); /* 2161 */
#endif /* MQRC_Q_MGR_QUIESCING */
#ifdef MQRC_Q_MGR_STOPPING
ADD_MQ_REASON_TXT(MQRC_Q_MGR_STOPPING, "Queue manager shutting down."); /* 2162 */
#endif /* MQRC_Q_MGR_STOPPING */
#ifdef MQRC_DUPLICATE_RECOV_COORD
ADD_MQ_REASON_TXT(MQRC_DUPLICATE_RECOV_COORD, "Recovery coordinator already exists."); /* 2163 */
#endif /* MQRC_DUPLICATE_RECOV_COORD */
#ifdef MQRC_PMO_ERROR
ADD_MQ_REASON_TXT(MQRC_PMO_ERROR, "Put-message options structure not valid."); /* 2173 */
#endif /* MQRC_PMO_ERROR */
#ifdef MQRC_API_EXIT_NOT_FOUND
ADD_MQ_REASON_TXT(MQRC_API_EXIT_NOT_FOUND, "The API crossing exit entry point could not be found."); /* 2182 */
#endif /* MQRC_API_EXIT_NOT_FOUND */
#ifdef MQRC_API_EXIT_LOAD_ERROR
ADD_MQ_REASON_TXT(MQRC_API_EXIT_LOAD_ERROR, "Unable to load API crossing exit."); /* 2183 */
#endif /* MQRC_API_EXIT_LOAD_ERROR */
#ifdef MQRC_REMOTE_Q_NAME_ERROR
ADD_MQ_REASON_TXT(MQRC_REMOTE_Q_NAME_ERROR, "Remote queue name not valid."); /* 2184 */
#endif /* MQRC_REMOTE_Q_NAME_ERROR */
#ifdef MQRC_INCONSISTENT_PERSISTENCE
ADD_MQ_REASON_TXT(MQRC_INCONSISTENT_PERSISTENCE, "Inconsistent persistence specification."); /* 2185 */
#endif /* MQRC_INCONSISTENT_PERSISTENCE */
#ifdef MQRC_GMO_ERROR
ADD_MQ_REASON_TXT(MQRC_GMO_ERROR, "Get-message options structure not valid."); /* 2186 */
#endif /* MQRC_GMO_ERROR */
#ifdef MQRC_CICS_BRIDGE_RESTRICTION
ADD_MQ_REASON_TXT(MQRC_CICS_BRIDGE_RESTRICTION, "Requested function not supported by CICS bridge."); /* 2187 */
#endif /* MQRC_CICS_BRIDGE_RESTRICTION */
#ifdef MQRC_STOPPED_BY_CLUSTER_EXIT
ADD_MQ_REASON_TXT(MQRC_STOPPED_BY_CLUSTER_EXIT, "Call rejected by cluster-workload exit."); /* 2188 */
#endif /* MQRC_STOPPED_BY_CLUSTER_EXIT */
#ifdef MQRC_CLUSTER_RESOLUTION_ERROR
ADD_MQ_REASON_TXT(MQRC_CLUSTER_RESOLUTION_ERROR, "Cluster name resolution failed."); /* 2189 */
#endif /* MQRC_CLUSTER_RESOLUTION_ERROR */
#ifdef MQRC_CONVERTED_STRING_TOO_BIG
ADD_MQ_REASON_TXT(MQRC_CONVERTED_STRING_TOO_BIG, "Converted string too big for field."); /* 2190 */
#endif /* MQRC_CONVERTED_STRING_TOO_BIG */
#ifdef MQRC_TMC_ERROR
ADD_MQ_REASON_TXT(MQRC_TMC_ERROR, "Character trigger message structure not valid."); /* 2191 */
#endif /* MQRC_TMC_ERROR */
#ifdef MQRC_PAGESET_FULL
ADD_MQ_REASON_TXT(MQRC_PAGESET_FULL, "Page set data set full."); /* 2192 */
#endif /* MQRC_PAGESET_FULL */
#ifdef MQRC_PAGESET_ERROR
ADD_MQ_REASON_TXT(MQRC_PAGESET_ERROR, "Error accessing page set data set."); /* 2193 */
#endif /* MQRC_PAGESET_ERROR */
#ifdef MQRC_NAME_NOT_VALID_FOR_TYPE
ADD_MQ_REASON_TXT(MQRC_NAME_NOT_VALID_FOR_TYPE, "Object name not valid for object type."); /* 2194 */
#endif /* MQRC_NAME_NOT_VALID_FOR_TYPE */
#ifdef MQRC_UNEXPECTED_ERROR
ADD_MQ_REASON_TXT(MQRC_UNEXPECTED_ERROR, "Unexpected error occurred."); /* 2195 */
#endif /* MQRC_UNEXPECTED_ERROR */
#ifdef MQRC_UNKNOWN_XMIT_Q
ADD_MQ_REASON_TXT(MQRC_UNKNOWN_XMIT_Q, "Unknown transmission queue."); /* 2196 */
#endif /* MQRC_UNKNOWN_XMIT_Q */
#ifdef MQRC_UNKNOWN_DEF_XMIT_Q
ADD_MQ_REASON_TXT(MQRC_UNKNOWN_DEF_XMIT_Q, "Unknown default transmission queue."); /* 2197 */
#endif /* MQRC_UNKNOWN_DEF_XMIT_Q */
#ifdef MQRC_DEF_XMIT_Q_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRC_DEF_XMIT_Q_TYPE_ERROR, "Default transmission queue not local."); /* 2198 */
#endif /* MQRC_DEF_XMIT_Q_TYPE_ERROR */
#ifdef MQRC_DEF_XMIT_Q_USAGE_ERROR
ADD_MQ_REASON_TXT(MQRC_DEF_XMIT_Q_USAGE_ERROR, "Default transmission queue usage error."); /* 2199 */
#endif /* MQRC_DEF_XMIT_Q_USAGE_ERROR */
#ifdef MQRC_NAME_IN_USE
ADD_MQ_REASON_TXT(MQRC_NAME_IN_USE, "Name in use."); /* 2201 */
#endif /* MQRC_NAME_IN_USE */
#ifdef MQRC_CONNECTION_QUIESCING
ADD_MQ_REASON_TXT(MQRC_CONNECTION_QUIESCING, "Connection quiescing."); /* 2202 */
#endif /* MQRC_CONNECTION_QUIESCING */
#ifdef MQRC_CONNECTION_STOPPING
ADD_MQ_REASON_TXT(MQRC_CONNECTION_STOPPING, "Connection shutting down."); /* 2203 */
#endif /* MQRC_CONNECTION_STOPPING */
#ifdef MQRC_ADAPTER_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRC_ADAPTER_NOT_AVAILABLE, "Adapter not available."); /* 2204 */
#endif /* MQRC_ADAPTER_NOT_AVAILABLE */
#ifdef MQRC_MSG_ID_ERROR
ADD_MQ_REASON_TXT(MQRC_MSG_ID_ERROR, "Message-identifier error."); /* 2206 */
#endif /* MQRC_MSG_ID_ERROR */
#ifdef MQRC_CORREL_ID_ERROR
ADD_MQ_REASON_TXT(MQRC_CORREL_ID_ERROR, "Correlation-identifier error."); /* 2207 */
#endif /* MQRC_CORREL_ID_ERROR */
#ifdef MQRC_FILE_SYSTEM_ERROR
ADD_MQ_REASON_TXT(MQRC_FILE_SYSTEM_ERROR, "File-system error."); /* 2208 */
#endif /* MQRC_FILE_SYSTEM_ERROR */
#ifdef MQRC_NO_MSG_LOCKED
ADD_MQ_REASON_TXT(MQRC_NO_MSG_LOCKED, "No message locked."); /* 2209 */
#endif /* MQRC_NO_MSG_LOCKED */
#ifdef MQRC_SOAP_DOTNET_ERROR
ADD_MQ_REASON_TXT(MQRC_SOAP_DOTNET_ERROR, "An exception from the .NET environment has been received and is included as an inner exception."); /* 2210 */
#endif /* MQRC_SOAP_DOTNET_ERROR */
#ifdef MQRC_SOAP_AXIS_ERROR
ADD_MQ_REASON_TXT(MQRC_SOAP_AXIS_ERROR, "An exception from the Axis environment has been received and is included as a chained exception."); /* 2211 */
#endif /* MQRC_SOAP_AXIS_ERROR */
#ifdef MQRC_SOAP_URL_ERROR
ADD_MQ_REASON_TXT(MQRC_SOAP_URL_ERROR, "The SOAP URL has been specified incorrectly."); /* 2212 */
#endif /* MQRC_SOAP_URL_ERROR */
#ifdef MQRC_CONNECTION_NOT_AUTHORIZED
ADD_MQ_REASON_TXT(MQRC_CONNECTION_NOT_AUTHORIZED, "Not authorized for connection."); /* 2217 */
#endif /* MQRC_CONNECTION_NOT_AUTHORIZED */
#ifdef MQRC_MSG_TOO_BIG_FOR_CHANNEL
ADD_MQ_REASON_TXT(MQRC_MSG_TOO_BIG_FOR_CHANNEL, "Message length greater than maximum for channel."); /* 2218 */
#endif /* MQRC_MSG_TOO_BIG_FOR_CHANNEL */
#ifdef MQRC_CALL_IN_PROGRESS
ADD_MQ_REASON_TXT(MQRC_CALL_IN_PROGRESS, "MQI call reentered before previous call complete."); /* 2219 */
#endif /* MQRC_CALL_IN_PROGRESS */
#ifdef MQRC_RMH_ERROR
ADD_MQ_REASON_TXT(MQRC_RMH_ERROR, "Reference message header structure not valid."); /* 2220 */
#endif /* MQRC_RMH_ERROR */
#ifdef MQRC_Q_MGR_ACTIVE
ADD_MQ_REASON_TXT(MQRC_Q_MGR_ACTIVE, "Queue manager created."); /* 2222 */
#endif /* MQRC_Q_MGR_ACTIVE */
#ifdef MQRC_Q_MGR_NOT_ACTIVE
ADD_MQ_REASON_TXT(MQRC_Q_MGR_NOT_ACTIVE, "Queue manager unavailable."); /* 2223 */
#endif /* MQRC_Q_MGR_NOT_ACTIVE */
#ifdef MQRC_Q_DEPTH_HIGH
ADD_MQ_REASON_TXT(MQRC_Q_DEPTH_HIGH, "Queue depth high limit reached or exceeded."); /* 2224 */
#endif /* MQRC_Q_DEPTH_HIGH */
#ifdef MQRC_Q_DEPTH_LOW
ADD_MQ_REASON_TXT(MQRC_Q_DEPTH_LOW, "Queue depth low limit reached or exceeded."); /* 2225 */
#endif /* MQRC_Q_DEPTH_LOW */
#ifdef MQRC_Q_SERVICE_INTERVAL_HIGH
ADD_MQ_REASON_TXT(MQRC_Q_SERVICE_INTERVAL_HIGH, "Queue service interval high."); /* 2226 */
#endif /* MQRC_Q_SERVICE_INTERVAL_HIGH */
#ifdef MQRC_Q_SERVICE_INTERVAL_OK
ADD_MQ_REASON_TXT(MQRC_Q_SERVICE_INTERVAL_OK, "Queue service interval ok."); /* 2227 */
#endif /* MQRC_Q_SERVICE_INTERVAL_OK */
#ifdef MQRC_RFH_HEADER_FIELD_ERROR
ADD_MQ_REASON_TXT(MQRC_RFH_HEADER_FIELD_ERROR, "An expected RFH header field was not found or had an invalid value."); /* 2228 */
#endif /* MQRC_RFH_HEADER_FIELD_ERROR */
#ifdef MQRC_RAS_PROPERTY_ERROR
ADD_MQ_REASON_TXT(MQRC_RAS_PROPERTY_ERROR, "There is an error related to the RAS property file."); /* 2229 */
#endif /* MQRC_RAS_PROPERTY_ERROR */
#ifdef MQRC_UNIT_OF_WORK_NOT_STARTED
ADD_MQ_REASON_TXT(MQRC_UNIT_OF_WORK_NOT_STARTED, "Unit of work not started."); /* 2232 */
#endif /* MQRC_UNIT_OF_WORK_NOT_STARTED */
#ifdef MQRC_CHANNEL_AUTO_DEF_OK
ADD_MQ_REASON_TXT(MQRC_CHANNEL_AUTO_DEF_OK, "Automatic channel definition succeeded."); /* 2233 */
#endif /* MQRC_CHANNEL_AUTO_DEF_OK */
#ifdef MQRC_CHANNEL_AUTO_DEF_ERROR
ADD_MQ_REASON_TXT(MQRC_CHANNEL_AUTO_DEF_ERROR, "Automatic channel definition failed."); /* 2234 */
#endif /* MQRC_CHANNEL_AUTO_DEF_ERROR */
#ifdef MQRC_CFH_ERROR
ADD_MQ_REASON_TXT(MQRC_CFH_ERROR, "PCF header structure not valid."); /* 2235 */
#endif /* MQRC_CFH_ERROR */
#ifdef MQRC_CFIL_ERROR
ADD_MQ_REASON_TXT(MQRC_CFIL_ERROR, "PCF integer list parameter structure not valid."); /* 2236 */
#endif /* MQRC_CFIL_ERROR */
#ifdef MQRC_CFIN_ERROR
ADD_MQ_REASON_TXT(MQRC_CFIN_ERROR, "PCF integer parameter structure not valid."); /* 2237 */
#endif /* MQRC_CFIN_ERROR */
#ifdef MQRC_CFSL_ERROR
ADD_MQ_REASON_TXT(MQRC_CFSL_ERROR, "PCF string list parameter structure not valid."); /* 2238 */
#endif /* MQRC_CFSL_ERROR */
#ifdef MQRC_CFST_ERROR
ADD_MQ_REASON_TXT(MQRC_CFST_ERROR, "PCF string parameter structure not valid."); /* 2239 */
#endif /* MQRC_CFST_ERROR */
#ifdef MQRC_INCOMPLETE_GROUP
ADD_MQ_REASON_TXT(MQRC_INCOMPLETE_GROUP, "Message group not complete."); /* 2241 */
#endif /* MQRC_INCOMPLETE_GROUP */
#ifdef MQRC_INCOMPLETE_MSG
ADD_MQ_REASON_TXT(MQRC_INCOMPLETE_MSG, "Logical message not complete."); /* 2242 */
#endif /* MQRC_INCOMPLETE_MSG */
#ifdef MQRC_INCONSISTENT_CCSIDS
ADD_MQ_REASON_TXT(MQRC_INCONSISTENT_CCSIDS, "Message segments have differing CCSIDs."); /* 2243 */
#endif /* MQRC_INCONSISTENT_CCSIDS */
#ifdef MQRC_INCONSISTENT_ENCODINGS
ADD_MQ_REASON_TXT(MQRC_INCONSISTENT_ENCODINGS, "Message segments have differing encodings."); /* 2244 */
#endif /* MQRC_INCONSISTENT_ENCODINGS */
#ifdef MQRC_INCONSISTENT_UOW
ADD_MQ_REASON_TXT(MQRC_INCONSISTENT_UOW, "Inconsistent unit-of-work specification."); /* 2245 */
#endif /* MQRC_INCONSISTENT_UOW */
#ifdef MQRC_INVALID_MSG_UNDER_CURSOR
ADD_MQ_REASON_TXT(MQRC_INVALID_MSG_UNDER_CURSOR, "Message under cursor not valid for retrieval."); /* 2246 */
#endif /* MQRC_INVALID_MSG_UNDER_CURSOR */
#ifdef MQRC_MATCH_OPTIONS_ERROR
ADD_MQ_REASON_TXT(MQRC_MATCH_OPTIONS_ERROR, "Match options not valid."); /* 2247 */
#endif /* MQRC_MATCH_OPTIONS_ERROR */
#ifdef MQRC_MDE_ERROR
ADD_MQ_REASON_TXT(MQRC_MDE_ERROR, "Message descriptor extension not valid."); /* 2248 */
#endif /* MQRC_MDE_ERROR */
#ifdef MQRC_MSG_FLAGS_ERROR
ADD_MQ_REASON_TXT(MQRC_MSG_FLAGS_ERROR, "Message flags not valid."); /* 2249 */
#endif /* MQRC_MSG_FLAGS_ERROR */
#ifdef MQRC_MSG_SEQ_NUMBER_ERROR
ADD_MQ_REASON_TXT(MQRC_MSG_SEQ_NUMBER_ERROR, "Message sequence number not valid."); /* 2250 */
#endif /* MQRC_MSG_SEQ_NUMBER_ERROR */
#ifdef MQRC_OFFSET_ERROR
ADD_MQ_REASON_TXT(MQRC_OFFSET_ERROR, "Message segment offset not valid."); /* 2251 */
#endif /* MQRC_OFFSET_ERROR */
#ifdef MQRC_ORIGINAL_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRC_ORIGINAL_LENGTH_ERROR, "Original length not valid."); /* 2252 */
#endif /* MQRC_ORIGINAL_LENGTH_ERROR */
#ifdef MQRC_SEGMENT_LENGTH_ZERO
ADD_MQ_REASON_TXT(MQRC_SEGMENT_LENGTH_ZERO, "Length of data in message segment is zero."); /* 2253 */
#endif /* MQRC_SEGMENT_LENGTH_ZERO */
#ifdef MQRC_UOW_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRC_UOW_NOT_AVAILABLE, "Unit of work not available for the queue manager to use."); /* 2255 */
#endif /* MQRC_UOW_NOT_AVAILABLE */
#ifdef MQRC_WRONG_GMO_VERSION
ADD_MQ_REASON_TXT(MQRC_WRONG_GMO_VERSION, "Wrong version of MQGMO supplied."); /* 2256 */
#endif /* MQRC_WRONG_GMO_VERSION */
#ifdef MQRC_WRONG_MD_VERSION
ADD_MQ_REASON_TXT(MQRC_WRONG_MD_VERSION, "Wrong version of MQMD supplied."); /* 2257 */
#endif /* MQRC_WRONG_MD_VERSION */
#ifdef MQRC_GROUP_ID_ERROR
ADD_MQ_REASON_TXT(MQRC_GROUP_ID_ERROR, "Group identifier not valid."); /* 2258 */
#endif /* MQRC_GROUP_ID_ERROR */
#ifdef MQRC_INCONSISTENT_BROWSE
ADD_MQ_REASON_TXT(MQRC_INCONSISTENT_BROWSE, "Inconsistent browse specification."); /* 2259 */
#endif /* MQRC_INCONSISTENT_BROWSE */
#ifdef MQRC_XQH_ERROR
ADD_MQ_REASON_TXT(MQRC_XQH_ERROR, "Transmission queue header structure not valid."); /* 2260 */
#endif /* MQRC_XQH_ERROR */
#ifdef MQRC_SRC_ENV_ERROR
ADD_MQ_REASON_TXT(MQRC_SRC_ENV_ERROR, "Source environment data error."); /* 2261 */
#endif /* MQRC_SRC_ENV_ERROR */
#ifdef MQRC_SRC_NAME_ERROR
ADD_MQ_REASON_TXT(MQRC_SRC_NAME_ERROR, "Source name data error."); /* 2262 */
#endif /* MQRC_SRC_NAME_ERROR */
#ifdef MQRC_DEST_ENV_ERROR
ADD_MQ_REASON_TXT(MQRC_DEST_ENV_ERROR, "Destination environment data error."); /* 2263 */
#endif /* MQRC_DEST_ENV_ERROR */
#ifdef MQRC_DEST_NAME_ERROR
ADD_MQ_REASON_TXT(MQRC_DEST_NAME_ERROR, "Destination name data error."); /* 2264 */
#endif /* MQRC_DEST_NAME_ERROR */
#ifdef MQRC_TM_ERROR
ADD_MQ_REASON_TXT(MQRC_TM_ERROR, "Trigger message structure not valid."); /* 2265 */
#endif /* MQRC_TM_ERROR */
#ifdef MQRC_CLUSTER_EXIT_ERROR
ADD_MQ_REASON_TXT(MQRC_CLUSTER_EXIT_ERROR, "Cluster workload exit failed."); /* 2266 */
#endif /* MQRC_CLUSTER_EXIT_ERROR */
#ifdef MQRC_CLUSTER_EXIT_LOAD_ERROR
ADD_MQ_REASON_TXT(MQRC_CLUSTER_EXIT_LOAD_ERROR, "Unable to load cluster workload exit."); /* 2267 */
#endif /* MQRC_CLUSTER_EXIT_LOAD_ERROR */
#ifdef MQRC_CLUSTER_PUT_INHIBITED
ADD_MQ_REASON_TXT(MQRC_CLUSTER_PUT_INHIBITED, "Put calls inhibited for all queues in cluster."); /* 2268 */
#endif /* MQRC_CLUSTER_PUT_INHIBITED */
#ifdef MQRC_CLUSTER_RESOURCE_ERROR
ADD_MQ_REASON_TXT(MQRC_CLUSTER_RESOURCE_ERROR, "An MQOPEN, MQPUT, or MQPUT1 call was issued for a cluster queue, but an error occurred whilst trying to use a resource required for clustering."); /* 2269 */
#endif /* MQRC_CLUSTER_RESOURCE_ERROR */
#ifdef MQRC_NO_DESTINATIONS_AVAILABLE
ADD_MQ_REASON_TXT(MQRC_NO_DESTINATIONS_AVAILABLE, "No destination queues available."); /* 2270 */
#endif /* MQRC_NO_DESTINATIONS_AVAILABLE */
#ifdef MQRC_CONN_TAG_IN_USE
ADD_MQ_REASON_TXT(MQRC_CONN_TAG_IN_USE, "An MQCONNX call was issued specifying one of the MQCNO_*_CONN_TAG_* options, but the call failed because the connection tag specified by ConnTag in MQCNO is in use by an active process or thread, or there is an unresolved unit of work that references this connection tag."); /* 2271 */
#endif /* MQRC_CONN_TAG_IN_USE */
#ifdef MQRC_PARTIALLY_CONVERTED
ADD_MQ_REASON_TXT(MQRC_PARTIALLY_CONVERTED, "On an MQGET call with the MQGMO_CONVERT option included in the GetMsgOpts parameter, one or more MQ header structures in the message data could not be converted to the specified target character set or encoding."); /* 2272 */
#endif /* MQRC_PARTIALLY_CONVERTED */
#ifdef MQRC_CONNECTION_ERROR
ADD_MQ_REASON_TXT(MQRC_CONNECTION_ERROR, "Error processing MQCONN call."); /* 2273 */
#endif /* MQRC_CONNECTION_ERROR */
#ifdef MQRC_OPTION_ENVIRONMENT_ERROR
ADD_MQ_REASON_TXT(MQRC_OPTION_ENVIRONMENT_ERROR, "Option not valid in environment."); /* 2274 */
#endif /* MQRC_OPTION_ENVIRONMENT_ERROR */
#ifdef MQRC_CD_ERROR
ADD_MQ_REASON_TXT(MQRC_CD_ERROR, "Channel definition not valid."); /* 2277 */
#endif /* MQRC_CD_ERROR */
#ifdef MQRC_CLIENT_CONN_ERROR
ADD_MQ_REASON_TXT(MQRC_CLIENT_CONN_ERROR, "Client connection fields not valid."); /* 2278 */
#endif /* MQRC_CLIENT_CONN_ERROR */
#ifdef MQRC_CHANNEL_STOPPED_BY_USER
ADD_MQ_REASON_TXT(MQRC_CHANNEL_STOPPED_BY_USER, "Channel stopped by user."); /* 2279 */
#endif /* MQRC_CHANNEL_STOPPED_BY_USER */
#ifdef MQRC_HCONFIG_ERROR
ADD_MQ_REASON_TXT(MQRC_HCONFIG_ERROR, "Configuration handle not valid."); /* 2280 */
#endif /* MQRC_HCONFIG_ERROR */
#ifdef MQRC_FUNCTION_ERROR
ADD_MQ_REASON_TXT(MQRC_FUNCTION_ERROR, "Function identifier not valid for service."); /* 2281 */
#endif /* MQRC_FUNCTION_ERROR */
#ifdef MQRC_CHANNEL_STARTED
ADD_MQ_REASON_TXT(MQRC_CHANNEL_STARTED, "Channel started."); /* 2282 */
#endif /* MQRC_CHANNEL_STARTED */
#ifdef MQRC_CHANNEL_STOPPED
ADD_MQ_REASON_TXT(MQRC_CHANNEL_STOPPED, "Channel stopped."); /* 2283 */
#endif /* MQRC_CHANNEL_STOPPED */
#ifdef MQRC_CHANNEL_CONV_ERROR
ADD_MQ_REASON_TXT(MQRC_CHANNEL_CONV_ERROR, "Channel conversion error."); /* 2284 */
#endif /* MQRC_CHANNEL_CONV_ERROR */
#ifdef MQRC_SERVICE_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRC_SERVICE_NOT_AVAILABLE, "Underlying service not available."); /* 2285 */
#endif /* MQRC_SERVICE_NOT_AVAILABLE */
#ifdef MQRC_INITIALIZATION_FAILED
ADD_MQ_REASON_TXT(MQRC_INITIALIZATION_FAILED, "Initialization failed for an undefined reason."); /* 2286 */
#endif /* MQRC_INITIALIZATION_FAILED */
#ifdef MQRC_TERMINATION_FAILED
ADD_MQ_REASON_TXT(MQRC_TERMINATION_FAILED, "Termination failed for an undefined reason."); /* 2287 */
#endif /* MQRC_TERMINATION_FAILED */
#ifdef MQRC_UNKNOWN_Q_NAME
ADD_MQ_REASON_TXT(MQRC_UNKNOWN_Q_NAME, "Queue name not found."); /* 2288 */
#endif /* MQRC_UNKNOWN_Q_NAME */
#ifdef MQRC_SERVICE_ERROR
ADD_MQ_REASON_TXT(MQRC_SERVICE_ERROR, "Unexpected error occurred accessing service."); /* 2289 */
#endif /* MQRC_SERVICE_ERROR */
#ifdef MQRC_Q_ALREADY_EXISTS
ADD_MQ_REASON_TXT(MQRC_Q_ALREADY_EXISTS, "Queue object already exists."); /* 2290 */
#endif /* MQRC_Q_ALREADY_EXISTS */
#ifdef MQRC_USER_ID_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRC_USER_ID_NOT_AVAILABLE, "Unable to determine the user ID."); /* 2291 */
#endif /* MQRC_USER_ID_NOT_AVAILABLE */
#ifdef MQRC_UNKNOWN_ENTITY
ADD_MQ_REASON_TXT(MQRC_UNKNOWN_ENTITY, "Entity unknown to service."); /* 2292 */
#endif /* MQRC_UNKNOWN_ENTITY */
#ifdef MQRC_UNKNOWN_REF_OBJECT
ADD_MQ_REASON_TXT(MQRC_UNKNOWN_REF_OBJECT, "Reference object unknown."); /* 2294 */
#endif /* MQRC_UNKNOWN_REF_OBJECT */
#ifdef MQRC_CHANNEL_ACTIVATED
ADD_MQ_REASON_TXT(MQRC_CHANNEL_ACTIVATED, "Channel activated."); /* 2295 */
#endif /* MQRC_CHANNEL_ACTIVATED */
#ifdef MQRC_CHANNEL_NOT_ACTIVATED
ADD_MQ_REASON_TXT(MQRC_CHANNEL_NOT_ACTIVATED, "Channel cannot be activated."); /* 2296 */
#endif /* MQRC_CHANNEL_NOT_ACTIVATED */
#ifdef MQRC_UOW_CANCELED
ADD_MQ_REASON_TXT(MQRC_UOW_CANCELED, "Unit of work canceled."); /* 2297 */
#endif /* MQRC_UOW_CANCELED */
#ifdef MQRC_FUNCTION_NOT_SUPPORTED
ADD_MQ_REASON_TXT(MQRC_FUNCTION_NOT_SUPPORTED, "The function requested is not available in the current environment."); /* 2298 */
#endif /* MQRC_FUNCTION_NOT_SUPPORTED */
#ifdef MQRC_SELECTOR_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRC_SELECTOR_TYPE_ERROR, "Selector has wrong data type."); /* 2299 */
#endif /* MQRC_SELECTOR_TYPE_ERROR */
#ifdef MQRC_COMMAND_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRC_COMMAND_TYPE_ERROR, "Command type not valid."); /* 2300 */
#endif /* MQRC_COMMAND_TYPE_ERROR */
#ifdef MQRC_MULTIPLE_INSTANCE_ERROR
ADD_MQ_REASON_TXT(MQRC_MULTIPLE_INSTANCE_ERROR, "Multiple instances of system data item not valid."); /* 2301 */
#endif /* MQRC_MULTIPLE_INSTANCE_ERROR */
#ifdef MQRC_SYSTEM_ITEM_NOT_ALTERABLE
ADD_MQ_REASON_TXT(MQRC_SYSTEM_ITEM_NOT_ALTERABLE, "System data item is read-only and cannot be altered."); /* 2302 */
#endif /* MQRC_SYSTEM_ITEM_NOT_ALTERABLE */
#ifdef MQRC_BAG_CONVERSION_ERROR
ADD_MQ_REASON_TXT(MQRC_BAG_CONVERSION_ERROR, "Data could not be converted into a bag."); /* 2303 */
#endif /* MQRC_BAG_CONVERSION_ERROR */
#ifdef MQRC_SELECTOR_OUT_OF_RANGE
ADD_MQ_REASON_TXT(MQRC_SELECTOR_OUT_OF_RANGE, "Selector not within valid range for call."); /* 2304 */
#endif /* MQRC_SELECTOR_OUT_OF_RANGE */
#ifdef MQRC_SELECTOR_NOT_UNIQUE
ADD_MQ_REASON_TXT(MQRC_SELECTOR_NOT_UNIQUE, "Selector occurs more than once in bag."); /* 2305 */
#endif /* MQRC_SELECTOR_NOT_UNIQUE */
#ifdef MQRC_INDEX_NOT_PRESENT
ADD_MQ_REASON_TXT(MQRC_INDEX_NOT_PRESENT, "Index not present."); /* 2306 */
#endif /* MQRC_INDEX_NOT_PRESENT */
#ifdef MQRC_STRING_ERROR
ADD_MQ_REASON_TXT(MQRC_STRING_ERROR, "String parameter not valid."); /* 2307 */
#endif /* MQRC_STRING_ERROR */
#ifdef MQRC_ENCODING_NOT_SUPPORTED
ADD_MQ_REASON_TXT(MQRC_ENCODING_NOT_SUPPORTED, "Encoding not supported."); /* 2308 */
#endif /* MQRC_ENCODING_NOT_SUPPORTED */
#ifdef MQRC_SELECTOR_NOT_PRESENT
ADD_MQ_REASON_TXT(MQRC_SELECTOR_NOT_PRESENT, "Selector not present in bag."); /* 2309 */
#endif /* MQRC_SELECTOR_NOT_PRESENT */
#ifdef MQRC_OUT_SELECTOR_ERROR
ADD_MQ_REASON_TXT(MQRC_OUT_SELECTOR_ERROR, "OutSelector parameter not valid."); /* 2310 */
#endif /* MQRC_OUT_SELECTOR_ERROR */
#ifdef MQRC_STRING_TRUNCATED
ADD_MQ_REASON_TXT(MQRC_STRING_TRUNCATED, "String truncated (too long for output buffer)."); /* 2311 */
#endif /* MQRC_STRING_TRUNCATED */
#ifdef MQRC_SELECTOR_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRC_SELECTOR_WRONG_TYPE, "Selector implies a data type not valid for call."); /* 2312 */
#endif /* MQRC_SELECTOR_WRONG_TYPE */
#ifdef MQRC_INCONSISTENT_ITEM_TYPE
ADD_MQ_REASON_TXT(MQRC_INCONSISTENT_ITEM_TYPE, "Data type of item differs from previous occurrence of selector."); /* 2313 */
#endif /* MQRC_INCONSISTENT_ITEM_TYPE */
#ifdef MQRC_INDEX_ERROR
ADD_MQ_REASON_TXT(MQRC_INDEX_ERROR, "Index not valid."); /* 2314 */
#endif /* MQRC_INDEX_ERROR */
#ifdef MQRC_SYSTEM_BAG_NOT_ALTERABLE
ADD_MQ_REASON_TXT(MQRC_SYSTEM_BAG_NOT_ALTERABLE, "System bag is read-only and cannot be altered."); /* 2315 */
#endif /* MQRC_SYSTEM_BAG_NOT_ALTERABLE */
#ifdef MQRC_ITEM_COUNT_ERROR
ADD_MQ_REASON_TXT(MQRC_ITEM_COUNT_ERROR, "ItemCount parameter not valid."); /* 2316 */
#endif /* MQRC_ITEM_COUNT_ERROR */
#ifdef MQRC_FORMAT_NOT_SUPPORTED
ADD_MQ_REASON_TXT(MQRC_FORMAT_NOT_SUPPORTED, "Format not supported."); /* 2317 */
#endif /* MQRC_FORMAT_NOT_SUPPORTED */
#ifdef MQRC_SELECTOR_NOT_SUPPORTED
ADD_MQ_REASON_TXT(MQRC_SELECTOR_NOT_SUPPORTED, "System selector not supported."); /* 2318 */
#endif /* MQRC_SELECTOR_NOT_SUPPORTED */
#ifdef MQRC_ITEM_VALUE_ERROR
ADD_MQ_REASON_TXT(MQRC_ITEM_VALUE_ERROR, "ItemValue parameter not valid."); /* 2319 */
#endif /* MQRC_ITEM_VALUE_ERROR */
#ifdef MQRC_HBAG_ERROR
ADD_MQ_REASON_TXT(MQRC_HBAG_ERROR, "Bag handle not valid."); /* 2320 */
#endif /* MQRC_HBAG_ERROR */
#ifdef MQRC_PARAMETER_MISSING
ADD_MQ_REASON_TXT(MQRC_PARAMETER_MISSING, "Parameter missing."); /* 2321 */
#endif /* MQRC_PARAMETER_MISSING */
#ifdef MQRC_CMD_SERVER_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRC_CMD_SERVER_NOT_AVAILABLE, "Command server not available."); /* 2322 */
#endif /* MQRC_CMD_SERVER_NOT_AVAILABLE */
#ifdef MQRC_STRING_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRC_STRING_LENGTH_ERROR, "StringLength parameter not valid."); /* 2323 */
#endif /* MQRC_STRING_LENGTH_ERROR */
#ifdef MQRC_INQUIRY_COMMAND_ERROR
ADD_MQ_REASON_TXT(MQRC_INQUIRY_COMMAND_ERROR, "Command code is not a recognized inquiry command."); /* 2324 */
#endif /* MQRC_INQUIRY_COMMAND_ERROR */
#ifdef MQRC_NESTED_BAG_NOT_SUPPORTED
ADD_MQ_REASON_TXT(MQRC_NESTED_BAG_NOT_SUPPORTED, "Input bag contains one or more nested bags."); /* 2325 */
#endif /* MQRC_NESTED_BAG_NOT_SUPPORTED */
#ifdef MQRC_BAG_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRC_BAG_WRONG_TYPE, "Bag has wrong type for intended use."); /* 2326 */
#endif /* MQRC_BAG_WRONG_TYPE */
#ifdef MQRC_ITEM_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRC_ITEM_TYPE_ERROR, "ItemType parameter not valid."); /* 2327 */
#endif /* MQRC_ITEM_TYPE_ERROR */
#ifdef MQRC_SYSTEM_BAG_NOT_DELETABLE
ADD_MQ_REASON_TXT(MQRC_SYSTEM_BAG_NOT_DELETABLE, "System bag is read-only and cannot be deleted."); /* 2328 */
#endif /* MQRC_SYSTEM_BAG_NOT_DELETABLE */
#ifdef MQRC_SYSTEM_ITEM_NOT_DELETABLE
ADD_MQ_REASON_TXT(MQRC_SYSTEM_ITEM_NOT_DELETABLE, "System data item is read-only and cannot be deleted."); /* 2329 */
#endif /* MQRC_SYSTEM_ITEM_NOT_DELETABLE */
#ifdef MQRC_CODED_CHAR_SET_ID_ERROR
ADD_MQ_REASON_TXT(MQRC_CODED_CHAR_SET_ID_ERROR, "Coded character set identifier parameter not valid."); /* 2330 */
#endif /* MQRC_CODED_CHAR_SET_ID_ERROR */
#ifdef MQRC_MSG_TOKEN_ERROR
ADD_MQ_REASON_TXT(MQRC_MSG_TOKEN_ERROR, "Use of message token not valid."); /* 2331 */
#endif /* MQRC_MSG_TOKEN_ERROR */
#ifdef MQRC_MISSING_WIH
ADD_MQ_REASON_TXT(MQRC_MISSING_WIH, "Message data does not begin with MQWIH."); /* 2332 */
#endif /* MQRC_MISSING_WIH */
#ifdef MQRC_WIH_ERROR
ADD_MQ_REASON_TXT(MQRC_WIH_ERROR, "MQWIH structure not valid."); /* 2333 */
#endif /* MQRC_WIH_ERROR */
#ifdef MQRC_RFH_ERROR
ADD_MQ_REASON_TXT(MQRC_RFH_ERROR, "MQRFH structure not valid."); /* 2334 */
#endif /* MQRC_RFH_ERROR */
#ifdef MQRC_RFH_STRING_ERROR
ADD_MQ_REASON_TXT(MQRC_RFH_STRING_ERROR, "NameValueString field not valid."); /* 2335 */
#endif /* MQRC_RFH_STRING_ERROR */
#ifdef MQRC_RFH_COMMAND_ERROR
ADD_MQ_REASON_TXT(MQRC_RFH_COMMAND_ERROR, "Command not valid."); /* 2336 */
#endif /* MQRC_RFH_COMMAND_ERROR */
#ifdef MQRC_RFH_PARM_ERROR
ADD_MQ_REASON_TXT(MQRC_RFH_PARM_ERROR, "Parameter not valid."); /* 2337 */
#endif /* MQRC_RFH_PARM_ERROR */
#ifdef MQRC_RFH_DUPLICATE_PARM
ADD_MQ_REASON_TXT(MQRC_RFH_DUPLICATE_PARM, "Duplicate parameter."); /* 2338 */
#endif /* MQRC_RFH_DUPLICATE_PARM */
#ifdef MQRC_RFH_PARM_MISSING
ADD_MQ_REASON_TXT(MQRC_RFH_PARM_MISSING, "Parameter missing."); /* 2339 */
#endif /* MQRC_RFH_PARM_MISSING */
#ifdef MQRC_CHAR_CONVERSION_ERROR
ADD_MQ_REASON_TXT(MQRC_CHAR_CONVERSION_ERROR, "This reason code is returned by the Java™ MQQueueManager constructor when a required character-set conversion is not available."); /* 2340 */
#endif /* MQRC_CHAR_CONVERSION_ERROR */
#ifdef MQRC_UCS2_CONVERSION_ERROR
ADD_MQ_REASON_TXT(MQRC_UCS2_CONVERSION_ERROR, "This reason code is returned by the Java™ MQQueueManager constructor when a required character set conversion is not available."); /* 2341 */
#endif /* MQRC_UCS2_CONVERSION_ERROR */
#ifdef MQRC_DB2_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRC_DB2_NOT_AVAILABLE, "An MQOPEN, MQPUT1, or MQSET call, or a command, was issued to access a shared queue, but it failed because the queue manager is not connected to a DB2® subsystem."); /* 2342 */
#endif /* MQRC_DB2_NOT_AVAILABLE */
#ifdef MQRC_OBJECT_NOT_UNIQUE
ADD_MQ_REASON_TXT(MQRC_OBJECT_NOT_UNIQUE, "An MQOPEN or MQPUT1 call, or a command, was issued to access a queue, but the call failed because the queue specified cannot be resolved unambiguously."); /* 2343 */
#endif /* MQRC_OBJECT_NOT_UNIQUE */
#ifdef MQRC_CONN_TAG_NOT_RELEASED
ADD_MQ_REASON_TXT(MQRC_CONN_TAG_NOT_RELEASED, "An MQDISC call was issued when there was a unit of work outstanding for the connection handle."); /* 2344 */
#endif /* MQRC_CONN_TAG_NOT_RELEASED */
#ifdef MQRC_CF_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRC_CF_NOT_AVAILABLE, "An MQOPEN or MQPUT1 call was issued to access a shared queue, but the allocation of the coupling-facility structure specified in the queue definition failed because there is no suitable coupling facility to hold the structure, based on the preference list in the active CFRM policy."); /* 2345 */
#endif /* MQRC_CF_NOT_AVAILABLE */
#ifdef MQRC_CF_STRUC_IN_USE
ADD_MQ_REASON_TXT(MQRC_CF_STRUC_IN_USE, "An MQI call or command was issued to operate on a shared queue, but the call failed because the coupling-facility structure specified in the queue definition is unavailable."); /* 2346 */
#endif /* MQRC_CF_STRUC_IN_USE */
#ifdef MQRC_CF_STRUC_LIST_HDR_IN_USE
ADD_MQ_REASON_TXT(MQRC_CF_STRUC_LIST_HDR_IN_USE, "An MQGET, MQOPEN, MQPUT1, or MQSET call was issued to access a shared queue, but the call failed because the list header associated with the coupling-facility structure specified in the queue definition is temporarily unavailable."); /* 2347 */
#endif /* MQRC_CF_STRUC_LIST_HDR_IN_USE */
#ifdef MQRC_CF_STRUC_AUTH_FAILED
ADD_MQ_REASON_TXT(MQRC_CF_STRUC_AUTH_FAILED, "An MQOPEN or MQPUT1 call was issued to access a shared queue, but the call failed because the user is not authorized to access the coupling-facility structure specified in the queue definition."); /* 2348 */
#endif /* MQRC_CF_STRUC_AUTH_FAILED */
#ifdef MQRC_CF_STRUC_ERROR
ADD_MQ_REASON_TXT(MQRC_CF_STRUC_ERROR, "An MQOPEN or MQPUT1 call was issued to access a shared queue, but the call failed because the coupling-facility structure name specified in the queue definition is not defined in the CFRM data set, or is not the name of a list structure."); /* 2349 */
#endif /* MQRC_CF_STRUC_ERROR */
#ifdef MQRC_CONN_TAG_NOT_USABLE
ADD_MQ_REASON_TXT(MQRC_CONN_TAG_NOT_USABLE, "An MQCONNX call was issued specifying one of the MQCNO_*_CONN_TAG_* options, but the call failed because the connection tag specified by ConnTag in MQCNO is being used by the queue manager for recovery processing, and this processing is delayed pending recovery of the coupling facility."); /* 2350 */
#endif /* MQRC_CONN_TAG_NOT_USABLE */
#ifdef MQRC_GLOBAL_UOW_CONFLICT
ADD_MQ_REASON_TXT(MQRC_GLOBAL_UOW_CONFLICT, "An attempt was made to use inside a global unit of work a connection handle that is participating in another global unit of work."); /* 2351 */
#endif /* MQRC_GLOBAL_UOW_CONFLICT */
#ifdef MQRC_LOCAL_UOW_CONFLICT
ADD_MQ_REASON_TXT(MQRC_LOCAL_UOW_CONFLICT, "An attempt was made to use inside a global unit of work a connection handle that is participating in a queue-manager coordinated local unit of work."); /* 2352 */
#endif /* MQRC_LOCAL_UOW_CONFLICT */
#ifdef MQRC_HANDLE_IN_USE_FOR_UOW
ADD_MQ_REASON_TXT(MQRC_HANDLE_IN_USE_FOR_UOW, "An attempt was made to use outside a unit of work a connection handle that is participating in a global unit of work."); /* 2353 */
#endif /* MQRC_HANDLE_IN_USE_FOR_UOW */
#ifdef MQRC_UOW_ENLISTMENT_ERROR
ADD_MQ_REASON_TXT(MQRC_UOW_ENLISTMENT_ERROR, "This reason code can occur for a variety of reasons."); /* 2354 */
#endif /* MQRC_UOW_ENLISTMENT_ERROR */
#ifdef MQRC_UOW_MIX_NOT_SUPPORTED
ADD_MQ_REASON_TXT(MQRC_UOW_MIX_NOT_SUPPORTED, "The mixture of calls used by the application to perform operations within a unit of work is not supported."); /* 2355 */
#endif /* MQRC_UOW_MIX_NOT_SUPPORTED */
#ifdef MQRC_WXP_ERROR
ADD_MQ_REASON_TXT(MQRC_WXP_ERROR, "An MQXCLWLN call was issued from a cluster workload exit to obtain the address of the next record in the chain, but the workload exit parameter structure ExitParms is not valid."); /* 2356 */
#endif /* MQRC_WXP_ERROR */
#ifdef MQRC_CURRENT_RECORD_ERROR
ADD_MQ_REASON_TXT(MQRC_CURRENT_RECORD_ERROR, "An MQXCLWLN call was issued from a cluster workload exit to obtain the address of the next record in the chain, but the address specified by the CurrentRecord parameter is not the address of a valid record."); /* 2357 */
#endif /* MQRC_CURRENT_RECORD_ERROR */
#ifdef MQRC_NEXT_OFFSET_ERROR
ADD_MQ_REASON_TXT(MQRC_NEXT_OFFSET_ERROR, "An MQXCLWLN call was issued from a cluster workload exit to obtain the address of the next record in the chain, but the offset specified by the NextOffset parameter is not valid."); /* 2358 */
#endif /* MQRC_NEXT_OFFSET_ERROR */
#ifdef MQRC_NO_RECORD_AVAILABLE
ADD_MQ_REASON_TXT(MQRC_NO_RECORD_AVAILABLE, "An MQXCLWLN call was issued from a cluster workload exit to obtain the address of the next record in the chain, but the current record is the last record in the chain."); /* 2359 */
#endif /* MQRC_NO_RECORD_AVAILABLE */
#ifdef MQRC_OBJECT_LEVEL_INCOMPATIBLE
ADD_MQ_REASON_TXT(MQRC_OBJECT_LEVEL_INCOMPATIBLE, "An MQOPEN or MQPUT1 call, or a command, was issued, but the definition of the object to be accessed is not compatible with the queue manager to which the application has connected."); /* 2360 */
#endif /* MQRC_OBJECT_LEVEL_INCOMPATIBLE */
#ifdef MQRC_NEXT_RECORD_ERROR
ADD_MQ_REASON_TXT(MQRC_NEXT_RECORD_ERROR, "An MQXCLWLN call was issued from a cluster workload exit to obtain the address of the next record in the chain, but the address specified for the NextRecord parameter is either null, not valid, or the address of read-only storage."); /* 2361 */
#endif /* MQRC_NEXT_RECORD_ERROR */
#ifdef MQRC_BACKOUT_THRESHOLD_REACHED
ADD_MQ_REASON_TXT(MQRC_BACKOUT_THRESHOLD_REACHED, "This reason code occurs only in the Reason field in an MQDLH structure, or in the Feedback field in the MQMD of a report message."); /* 2362 */
#endif /* MQRC_BACKOUT_THRESHOLD_REACHED */
#ifdef MQRC_MSG_NOT_MATCHED
ADD_MQ_REASON_TXT(MQRC_MSG_NOT_MATCHED, "This reason code occurs only in the Reason field in an MQDLH structure, or in the Feedback field in the MQMD of a report message."); /* 2363 */
#endif /* MQRC_MSG_NOT_MATCHED */
#ifdef MQRC_JMS_FORMAT_ERROR
ADD_MQ_REASON_TXT(MQRC_JMS_FORMAT_ERROR, "This reason code is generated by JMS applications that use either:ConnectionConsumers Activation Specifications WebSphere Application Server Listener Ports and connect to a WebSphere MQ queue manager using WebSphere MQ messaging provider migration mode."); /* 2364 */
#endif /* MQRC_JMS_FORMAT_ERROR */
#ifdef MQRC_SEGMENTS_NOT_SUPPORTED
ADD_MQ_REASON_TXT(MQRC_SEGMENTS_NOT_SUPPORTED, "An MQPUT call was issued to put a segment of a logical message, but the queue on which the message is to be placed has an IndexType of MQIT_GROUP_ID."); /* 2365 */
#endif /* MQRC_SEGMENTS_NOT_SUPPORTED */
#ifdef MQRC_WRONG_CF_LEVEL
ADD_MQ_REASON_TXT(MQRC_WRONG_CF_LEVEL, "An MQOPEN or MQPUT1 call was issued specifying a shared queue, but the queue requires a coupling-facility structure with a different level of capability."); /* 2366 */
#endif /* MQRC_WRONG_CF_LEVEL */
#ifdef MQRC_CONFIG_CREATE_OBJECT
ADD_MQ_REASON_TXT(MQRC_CONFIG_CREATE_OBJECT, "Create Object"); /* 2367 */
#endif /* MQRC_CONFIG_CREATE_OBJECT */
#ifdef MQRC_CONFIG_CHANGE_OBJECT
ADD_MQ_REASON_TXT(MQRC_CONFIG_CHANGE_OBJECT, "Change Object"); /* 2368 */
#endif /* MQRC_CONFIG_CHANGE_OBJECT */
#ifdef MQRC_CONFIG_DELETE_OBJECT
ADD_MQ_REASON_TXT(MQRC_CONFIG_DELETE_OBJECT, "Delete Object"); /* 2369 */
#endif /* MQRC_CONFIG_DELETE_OBJECT */
#ifdef MQRC_CONFIG_REFRESH_OBJECT
ADD_MQ_REASON_TXT(MQRC_CONFIG_REFRESH_OBJECT, "Refresh Object"); /* 2370 */
#endif /* MQRC_CONFIG_REFRESH_OBJECT */
#ifdef MQRC_CHANNEL_SSL_ERROR
ADD_MQ_REASON_TXT(MQRC_CHANNEL_SSL_ERROR, "This condition is detected when a connection cannot be established due to an SSL key-exchange or authentication failure."); /* 2371 */
#endif /* MQRC_CHANNEL_SSL_ERROR */
#ifdef MQRC_CF_STRUC_FAILED
ADD_MQ_REASON_TXT(MQRC_CF_STRUC_FAILED, "An MQI call or command was issued to access a shared queue, but the call failed because the coupling-facility structure used for the shared queue had failed."); /* 2373 */
#endif /* MQRC_CF_STRUC_FAILED */
#ifdef MQRC_API_EXIT_ERROR
ADD_MQ_REASON_TXT(MQRC_API_EXIT_ERROR, "An API exit function returned an invalid response code, or failed in some other way."); /* 2374 */
#endif /* MQRC_API_EXIT_ERROR */
#ifdef MQRC_API_EXIT_INIT_ERROR
ADD_MQ_REASON_TXT(MQRC_API_EXIT_INIT_ERROR, "The queue manager encountered an error while attempting to initialize the execution environment for an API exit function."); /* 2375 */
#endif /* MQRC_API_EXIT_INIT_ERROR */
#ifdef MQRC_API_EXIT_TERM_ERROR
ADD_MQ_REASON_TXT(MQRC_API_EXIT_TERM_ERROR, "The queue manager encountered an error while attempting to terminate the execution environment for an API exit function."); /* 2376 */
#endif /* MQRC_API_EXIT_TERM_ERROR */
#ifdef MQRC_EXIT_REASON_ERROR
ADD_MQ_REASON_TXT(MQRC_EXIT_REASON_ERROR, "An MQXEP call was issued by an API exit function, but the value specified for the ExitReason parameter is either not valid, or not supported for the specified function identifier Function."); /* 2377 */
#endif /* MQRC_EXIT_REASON_ERROR */
#ifdef MQRC_RESERVED_VALUE_ERROR
ADD_MQ_REASON_TXT(MQRC_RESERVED_VALUE_ERROR, "An MQXEP call was issued by an API exit function, but the value specified for the Reserved parameter is not valid."); /* 2378 */
#endif /* MQRC_RESERVED_VALUE_ERROR */
#ifdef MQRC_NO_DATA_AVAILABLE
ADD_MQ_REASON_TXT(MQRC_NO_DATA_AVAILABLE, "This reason should be returned by the MQZ_ENUMERATE_AUTHORITY_DATA installable service component when there is no more authority data to return to the invoker of the service component."); /* 2379 */
#endif /* MQRC_NO_DATA_AVAILABLE */
#ifdef MQRC_SCO_ERROR
ADD_MQ_REASON_TXT(MQRC_SCO_ERROR, "On an MQCONNX call, the MQSCO structure is not valid for one of the following reasons: The StrucId field is not MQSCO_STRUC_ID."); /* 2380 */
#endif /* MQRC_SCO_ERROR */
#ifdef MQRC_KEY_REPOSITORY_ERROR
ADD_MQ_REASON_TXT(MQRC_KEY_REPOSITORY_ERROR, "On an MQCONN or MQCONNX call, the location of the key repository is either not specified, not valid, or results in an error when used to access the key repository."); /* 2381 */
#endif /* MQRC_KEY_REPOSITORY_ERROR */
#ifdef MQRC_CRYPTO_HARDWARE_ERROR
ADD_MQ_REASON_TXT(MQRC_CRYPTO_HARDWARE_ERROR, "On an MQCONN or MQCONNX call, the configuration string for the cryptographic hardware is not valid, or results in an error when used to configure the cryptographic hardware."); /* 2382 */
#endif /* MQRC_CRYPTO_HARDWARE_ERROR */
#ifdef MQRC_AUTH_INFO_REC_COUNT_ERROR
ADD_MQ_REASON_TXT(MQRC_AUTH_INFO_REC_COUNT_ERROR, "On an MQCONNX call, the AuthInfoRecCount field in the MQSCO structure specifies a value that is less than zero."); /* 2383 */
#endif /* MQRC_AUTH_INFO_REC_COUNT_ERROR */
#ifdef MQRC_AUTH_INFO_REC_ERROR
ADD_MQ_REASON_TXT(MQRC_AUTH_INFO_REC_ERROR, "On an MQCONNX call, the MQSCO structure does not specify the address of the MQAIR records correctly."); /* 2384 */
#endif /* MQRC_AUTH_INFO_REC_ERROR */
#ifdef MQRC_AIR_ERROR
ADD_MQ_REASON_TXT(MQRC_AIR_ERROR, "On an MQCONNX call, an MQAIR record is not valid for one of the following reasons: The StrucId field is not MQAIR_STRUC_ID."); /* 2385 */
#endif /* MQRC_AIR_ERROR */
#ifdef MQRC_AUTH_INFO_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRC_AUTH_INFO_TYPE_ERROR, "On an MQCONNX call, the AuthInfoType field in an MQAIR record specifies a value that is not valid."); /* 2386 */
#endif /* MQRC_AUTH_INFO_TYPE_ERROR */
#ifdef MQRC_AUTH_INFO_CONN_NAME_ERROR
ADD_MQ_REASON_TXT(MQRC_AUTH_INFO_CONN_NAME_ERROR, "On an MQCONNX call, the AuthInfoConnName field in an MQAIR record specifies a value that is not valid."); /* 2387 */
#endif /* MQRC_AUTH_INFO_CONN_NAME_ERROR */
#ifdef MQRC_LDAP_USER_NAME_ERROR
ADD_MQ_REASON_TXT(MQRC_LDAP_USER_NAME_ERROR, "On an MQCONNX call, an LDAP user name in an MQAIR record is not specified correctly."); /* 2388 */
#endif /* MQRC_LDAP_USER_NAME_ERROR */
#ifdef MQRC_LDAP_USER_NAME_LENGTH_ERR
ADD_MQ_REASON_TXT(MQRC_LDAP_USER_NAME_LENGTH_ERR, "On an MQCONNX call, the LDAPUserNameLength field in an MQAIR record specifies a value that is less than zero."); /* 2389 */
#endif /* MQRC_LDAP_USER_NAME_LENGTH_ERR */
#ifdef MQRC_LDAP_PASSWORD_ERROR
ADD_MQ_REASON_TXT(MQRC_LDAP_PASSWORD_ERROR, "On an MQCONNX call, the LDAPPassword field in an MQAIR record specifies a value when no value is allowed."); /* 2390 */
#endif /* MQRC_LDAP_PASSWORD_ERROR */
#ifdef MQRC_SSL_ALREADY_INITIALIZED
ADD_MQ_REASON_TXT(MQRC_SSL_ALREADY_INITIALIZED, "An MQCONN or MQCONNX call was issued with SSL configuration options specified, but the SSL environment had already been initialized."); /* 2391 */
#endif /* MQRC_SSL_ALREADY_INITIALIZED */
#ifdef MQRC_SSL_CONFIG_ERROR
ADD_MQ_REASON_TXT(MQRC_SSL_CONFIG_ERROR, "On an MQCONNX call, the MQCNO structure does not specify the MQSCO structure correctly."); /* 2392 */
#endif /* MQRC_SSL_CONFIG_ERROR */
#ifdef MQRC_SSL_INITIALIZATION_ERROR
ADD_MQ_REASON_TXT(MQRC_SSL_INITIALIZATION_ERROR, "An MQCONN or MQCONNX call was issued with SSL configuration options specified, but an error occurred during the initialization of the SSL environment."); /* 2393 */
#endif /* MQRC_SSL_INITIALIZATION_ERROR */
#ifdef MQRC_Q_INDEX_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRC_Q_INDEX_TYPE_ERROR, "An MQGET call was issued specifying one or more of the following options: MQGMO_ALL_MSGS_AVAILABLE MQGMO_ALL_SEGMENTS_AVAILABLE MQGMO_COMPLETE_MSG MQGMO_LOGICAL_ORDER but the call failed because the queue is not indexed by group identifier."); /* 2394 */
#endif /* MQRC_Q_INDEX_TYPE_ERROR */
#ifdef MQRC_CFBS_ERROR
ADD_MQ_REASON_TXT(MQRC_CFBS_ERROR, "An MQPUT or MQPUT1 call was issued, but the message data contains an MQCFBS structure that is not valid."); /* 2395 */
#endif /* MQRC_CFBS_ERROR */
#ifdef MQRC_SSL_NOT_ALLOWED
ADD_MQ_REASON_TXT(MQRC_SSL_NOT_ALLOWED, "A connection to a queue manager was requested, specifying SSL encryption."); /* 2396 */
#endif /* MQRC_SSL_NOT_ALLOWED */
#ifdef MQRC_JSSE_ERROR
ADD_MQ_REASON_TXT(MQRC_JSSE_ERROR, "JSSE reported an error (for example, while connecting to a queue manager using SSL encryption)."); /* 2397 */
#endif /* MQRC_JSSE_ERROR */
#ifdef MQRC_SSL_PEER_NAME_MISMATCH
ADD_MQ_REASON_TXT(MQRC_SSL_PEER_NAME_MISMATCH, "The application attempted to connect to the queue manager using SSL encryption, but the distinguished name presented by the queue manager does not match the specified pattern."); /* 2398 */
#endif /* MQRC_SSL_PEER_NAME_MISMATCH */
#ifdef MQRC_SSL_PEER_NAME_ERROR
ADD_MQ_REASON_TXT(MQRC_SSL_PEER_NAME_ERROR, "The application specified a peer name of incorrect format."); /* 2399 */
#endif /* MQRC_SSL_PEER_NAME_ERROR */
#ifdef MQRC_UNSUPPORTED_CIPHER_SUITE
ADD_MQ_REASON_TXT(MQRC_UNSUPPORTED_CIPHER_SUITE, "A connection to a queue manager was requested, specifying SSL encryption."); /* 2400 */
#endif /* MQRC_UNSUPPORTED_CIPHER_SUITE */
#ifdef MQRC_SSL_CERTIFICATE_REVOKED
ADD_MQ_REASON_TXT(MQRC_SSL_CERTIFICATE_REVOKED, "A connection to a queue manager was requested, specifying SSL encryption."); /* 2401 */
#endif /* MQRC_SSL_CERTIFICATE_REVOKED */
#ifdef MQRC_SSL_CERT_STORE_ERROR
ADD_MQ_REASON_TXT(MQRC_SSL_CERT_STORE_ERROR, "A connection to a queue manager was requested, specifying SSL encryption."); /* 2402 */
#endif /* MQRC_SSL_CERT_STORE_ERROR */
#ifdef MQRC_CLIENT_EXIT_LOAD_ERROR
ADD_MQ_REASON_TXT(MQRC_CLIENT_EXIT_LOAD_ERROR, "The external user exit required for a client connection could not be loaded because the shared library specified for it cannot be found, or the entry point specified for it cannot be found."); /* 2406 */
#endif /* MQRC_CLIENT_EXIT_LOAD_ERROR */
#ifdef MQRC_CLIENT_EXIT_ERROR
ADD_MQ_REASON_TXT(MQRC_CLIENT_EXIT_ERROR, "A failure occured while executing a non-Java user exit for a client connection."); /* 2407 */
#endif /* MQRC_CLIENT_EXIT_ERROR */
#ifdef MQRC_SSL_KEY_RESET_ERROR
ADD_MQ_REASON_TXT(MQRC_SSL_KEY_RESET_ERROR, "On an MQCONN or MQCONNX call, the value of the SSL key reset count is not in the valid range of 0 through 999 999 999."); /* 2409 */
#endif /* MQRC_SSL_KEY_RESET_ERROR */
#ifdef MQRC_LOGGER_STATUS
ADD_MQ_REASON_TXT(MQRC_LOGGER_STATUS, "This condition is detected when a logger event occurs."); /* 2411 */
#endif /* MQRC_LOGGER_STATUS */
#ifdef MQRC_COMMAND_MQSC
ADD_MQ_REASON_TXT(MQRC_COMMAND_MQSC, "This condition is detected when an MQSC command is executed."); /* 2412 */
#endif /* MQRC_COMMAND_MQSC */
#ifdef MQRC_COMMAND_PCF
ADD_MQ_REASON_TXT(MQRC_COMMAND_PCF, "This condition is detected when a PCF command is executed."); /* 2413 */
#endif /* MQRC_COMMAND_PCF */
#ifdef MQRC_CFIF_ERROR
ADD_MQ_REASON_TXT(MQRC_CFIF_ERROR, "An MQPUT or MQPUT1 call was issued, but the message data contains an MQCFIF structure that is not valid."); /* 2414 */
#endif /* MQRC_CFIF_ERROR */
#ifdef MQRC_CFSF_ERROR
ADD_MQ_REASON_TXT(MQRC_CFSF_ERROR, "An MQPUT or MQPUT1 call was issued, but the message data contains an MQCFSF structure that is not valid."); /* 2415 */
#endif /* MQRC_CFSF_ERROR */
#ifdef MQRC_CFGR_ERROR
ADD_MQ_REASON_TXT(MQRC_CFGR_ERROR, "An MQPUT or MQPUT1 call was issued, but the message data contains an MQCFGR structure that is not valid."); /* 2416 */
#endif /* MQRC_CFGR_ERROR */
#ifdef MQRC_MSG_NOT_ALLOWED_IN_GROUP
ADD_MQ_REASON_TXT(MQRC_MSG_NOT_ALLOWED_IN_GROUP, "An MQPUT or MQPUT1 call was issued to put a message in a group but it is not valid to put such a message in a group."); /* 2417 */
#endif /* MQRC_MSG_NOT_ALLOWED_IN_GROUP */
#ifdef MQRC_FILTER_OPERATOR_ERROR
ADD_MQ_REASON_TXT(MQRC_FILTER_OPERATOR_ERROR, "The Operator parameter supplied is not valid."); /* 2418 */
#endif /* MQRC_FILTER_OPERATOR_ERROR */
#ifdef MQRC_NESTED_SELECTOR_ERROR
ADD_MQ_REASON_TXT(MQRC_NESTED_SELECTOR_ERROR, "An mqAddBag call was issued, but the bag to be nested contained a data item with an inconsistent selector."); /* 2419 */
#endif /* MQRC_NESTED_SELECTOR_ERROR */
#ifdef MQRC_EPH_ERROR
ADD_MQ_REASON_TXT(MQRC_EPH_ERROR, "An MQPUT or MQPUT1 call was issued, but the message data contains an MQEPH structure that is not valid."); /* 2420 */
#endif /* MQRC_EPH_ERROR */
#ifdef MQRC_RFH_FORMAT_ERROR
ADD_MQ_REASON_TXT(MQRC_RFH_FORMAT_ERROR, "The message contains an MQRFH structure, but its format is incorrect."); /* 2421 */
#endif /* MQRC_RFH_FORMAT_ERROR */
#ifdef MQRC_CFBF_ERROR
ADD_MQ_REASON_TXT(MQRC_CFBF_ERROR, "An MQPUT or MQPUT1 call was issued, but the message data contains an MQCFBF structure that is not valid."); /* 2422 */
#endif /* MQRC_CFBF_ERROR */
#ifdef MQRC_CLIENT_CHANNEL_CONFLICT
ADD_MQ_REASON_TXT(MQRC_CLIENT_CHANNEL_CONFLICT, "A client channel definition table was specified for determining the name of the channel, but the name has already been defined."); /* 2423 */
#endif /* MQRC_CLIENT_CHANNEL_CONFLICT */
#ifdef MQRC_SD_ERROR
ADD_MQ_REASON_TXT(MQRC_SD_ERROR, "On the MQSUB call, the Subscription Descriptor MQSD is not valid."); /* 2424 */
#endif /* MQRC_SD_ERROR */
#ifdef MQRC_TOPIC_STRING_ERROR
ADD_MQ_REASON_TXT(MQRC_TOPIC_STRING_ERROR, "On the MQOPEN or MQPUT1 call in the Object Descriptor MQOD, or on the MQSUB call in the Subscription Descriptor MQSD the resultant full topic string is not valid."); /* 2425 */
#endif /* MQRC_TOPIC_STRING_ERROR */
#ifdef MQRC_STS_ERROR
ADD_MQ_REASON_TXT(MQRC_STS_ERROR, "On an MQSTAT call, the MQSTS structure is not valid."); /* 2426 */
#endif /* MQRC_STS_ERROR */
#ifdef MQRC_NO_SUBSCRIPTION
ADD_MQ_REASON_TXT(MQRC_NO_SUBSCRIPTION, "An MQSUB call using option MQSO_RESUME was made specifying a full subscription name that does not match any existing subscription."); /* 2428 */
#endif /* MQRC_NO_SUBSCRIPTION */
#ifdef MQRC_SUBSCRIPTION_IN_USE
ADD_MQ_REASON_TXT(MQRC_SUBSCRIPTION_IN_USE, "An MQSUB call using option MQSO_RESUME was made specifying a full subscription name that is in use."); /* 2429 */
#endif /* MQRC_SUBSCRIPTION_IN_USE */
#ifdef MQRC_STAT_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRC_STAT_TYPE_ERROR, "The STS parameter contains options that are not valid for the MQSTAT call."); /* 2430 */
#endif /* MQRC_STAT_TYPE_ERROR */
#ifdef MQRC_SUB_USER_DATA_ERROR
ADD_MQ_REASON_TXT(MQRC_SUB_USER_DATA_ERROR, "On the MQSUB call in the Subscription Descriptor MQSD the SubUserData field is not valid."); /* 2431 */
#endif /* MQRC_SUB_USER_DATA_ERROR */
#ifdef MQRC_SUB_ALREADY_EXISTS
ADD_MQ_REASON_TXT(MQRC_SUB_ALREADY_EXISTS, "An MQSUB call was issued to create a subscription, using the MQSO_CREATE option, but a subscription using the same SubName and ObjectString already exists."); /* 2432 */
#endif /* MQRC_SUB_ALREADY_EXISTS */
#ifdef MQRC_IDENTITY_MISMATCH
ADD_MQ_REASON_TXT(MQRC_IDENTITY_MISMATCH, "An MQSUB call using either MQSO_RESUME or MQSO_ALTER was made against a subscription that has the MQSO_FIXED_USERID option set, by a userid other than the one recorded as owning the subscription."); /* 2434 */
#endif /* MQRC_IDENTITY_MISMATCH */
#ifdef MQRC_ALTER_SUB_ERROR
ADD_MQ_REASON_TXT(MQRC_ALTER_SUB_ERROR, "An MQSUB call using option MQSO_ALTER was made changing a subscription that was created with the MQSO_IMMUTABLE option."); /* 2435 */
#endif /* MQRC_ALTER_SUB_ERROR */
#ifdef MQRC_DURABILITY_NOT_ALLOWED
ADD_MQ_REASON_TXT(MQRC_DURABILITY_NOT_ALLOWED, "An MQSUB call using the MQSO_DURABLE option failed."); /* 2436 */
#endif /* MQRC_DURABILITY_NOT_ALLOWED */
#ifdef MQRC_NO_RETAINED_MSG
ADD_MQ_REASON_TXT(MQRC_NO_RETAINED_MSG, "An MQSUBRQ call was made to a topic to request that any retained publications for this topic are sent to the subscriber."); /* 2437 */
#endif /* MQRC_NO_RETAINED_MSG */
#ifdef MQRC_SRO_ERROR
ADD_MQ_REASON_TXT(MQRC_SRO_ERROR, "On the MQSUBRQ call, the Subscription Request Options MQSRO is not valid."); /* 2438 */
#endif /* MQRC_SRO_ERROR */
#ifdef MQRC_SUB_NAME_ERROR
ADD_MQ_REASON_TXT(MQRC_SUB_NAME_ERROR, "On the MQSUB call in the Subscription Descriptor MQSD the SubName field is not valid or has been omitted."); /* 2440 */
#endif /* MQRC_SUB_NAME_ERROR */
#ifdef MQRC_OBJECT_STRING_ERROR
ADD_MQ_REASON_TXT(MQRC_OBJECT_STRING_ERROR, "On the MQOPEN or MQPUT1 call in the Object Descriptor MQOD, or on the MQSUB call in the Subscription Descriptor MQSD the ObjectString field is not valid."); /* 2441 */
#endif /* MQRC_OBJECT_STRING_ERROR */
#ifdef MQRC_PROPERTY_NAME_ERROR
ADD_MQ_REASON_TXT(MQRC_PROPERTY_NAME_ERROR, "An attempt was made to set a property with an invalid name."); /* 2442 */
#endif /* MQRC_PROPERTY_NAME_ERROR */
#ifdef MQRC_SEGMENTATION_NOT_ALLOWED
ADD_MQ_REASON_TXT(MQRC_SEGMENTATION_NOT_ALLOWED, "An MQPUT or MQPUT1 call was issued to put a segmented message or a message that may be broken up into smaller segments (MQMF_SEGMENTATION_ALLOWED)."); /* 2443 */
#endif /* MQRC_SEGMENTATION_NOT_ALLOWED */
#ifdef MQRC_CBD_ERROR
ADD_MQ_REASON_TXT(MQRC_CBD_ERROR, "a MQCB call the MQCBD structure is not valid for one of the following reasons: The StrucId field is not MQCBD_STRUC_ID The Version field is specifies a value that is not valid or is not supported The parameter pointer is not valid."); /* 2444 */
#endif /* MQRC_CBD_ERROR */
#ifdef MQRC_CTLO_ERROR
ADD_MQ_REASON_TXT(MQRC_CTLO_ERROR, "On a MQCTL call the MQCTLO structure is not valid for one of the following reasons: The StrucId field is not MQCTLO_STRUC_ID The Version field is specifies a value that is not valid or is not supported The parameter pointer is not valid."); /* 2445 */
#endif /* MQRC_CTLO_ERROR */
#ifdef MQRC_NO_CALLBACKS_ACTIVE
ADD_MQ_REASON_TXT(MQRC_NO_CALLBACKS_ACTIVE, "An MQCTL call was made with an Operation of MQOP_START_WAIT and has returned because there are no currently defined callbacks which are not suspended."); /* 2446 */
#endif /* MQRC_NO_CALLBACKS_ACTIVE */
#ifdef MQRC_CALLBACK_NOT_REGISTERED
ADD_MQ_REASON_TXT(MQRC_CALLBACK_NOT_REGISTERED, "An attempt to issue an MQCB call has been made against an object handle which does not currently have a registered callback."); /* 2448 */
#endif /* MQRC_CALLBACK_NOT_REGISTERED */
#ifdef MQRC_OPERATION_NOT_ALLOWED
ADD_MQ_REASON_TXT(MQRC_OPERATION_NOT_ALLOWED, "An MQCTL call was made with an Operation that is not allowed because of the state of asynchronous consumption on the hConn is currently in."); /* 2449 */
#endif /* MQRC_OPERATION_NOT_ALLOWED */
#ifdef MQRC_OPTIONS_CHANGED
ADD_MQ_REASON_TXT(MQRC_OPTIONS_CHANGED, "An MQGET call on a queue handle opened using MQOO_READ_AHEAD (or resolved to that value through the queue’s default value) has altered an option that is required to be consistent between MQGET calls."); /* 2457 */
#endif /* MQRC_OPTIONS_CHANGED */
#ifdef MQRC_READ_AHEAD_MSGS
ADD_MQ_REASON_TXT(MQRC_READ_AHEAD_MSGS, "On an MQCLOSE call, the option MQCO_QUIESCE was used and there are still messages stored in client read ahead buffer that were sent to the client ahead of an application requesting them and have not yet been consumed by the application."); /* 2458 */
#endif /* MQRC_READ_AHEAD_MSGS */
#ifdef MQRC_SELECTOR_SYNTAX_ERROR
ADD_MQ_REASON_TXT(MQRC_SELECTOR_SYNTAX_ERROR, "An MQOPEN, MQPUT1 or MQSUB call was issued but a selection string was specified which contained a syntax error."); /* 2459 */
#endif /* MQRC_SELECTOR_SYNTAX_ERROR */
#ifdef MQRC_HMSG_ERROR
ADD_MQ_REASON_TXT(MQRC_HMSG_ERROR, "On an MQCRTMH, MQDLTMH, MQSETMP, MQINQMP or MQDLT call, a message handle supplied is not valid."); /* 2460 */
#endif /* MQRC_HMSG_ERROR */
#ifdef MQRC_CMHO_ERROR
ADD_MQ_REASON_TXT(MQRC_CMHO_ERROR, "On an MQCRTMH call, the create message handle options structure MQCMHO is not valid."); /* 2461 */
#endif /* MQRC_CMHO_ERROR */
#ifdef MQRC_DMHO_ERROR
ADD_MQ_REASON_TXT(MQRC_DMHO_ERROR, "On an MQDLTMH call, the delete message handle options structure MQDMHO is not valid."); /* 2462 */
#endif /* MQRC_DMHO_ERROR */
#ifdef MQRC_SMPO_ERROR
ADD_MQ_REASON_TXT(MQRC_SMPO_ERROR, "On an MQSETMP call, the set message property options structure MQSMPO is not valid."); /* 2463 */
#endif /* MQRC_SMPO_ERROR */
#ifdef MQRC_IMPO_ERROR
ADD_MQ_REASON_TXT(MQRC_IMPO_ERROR, "On an MQINQMP call, the inquire message property options structure MQIMPO is not valid."); /* 2464 */
#endif /* MQRC_IMPO_ERROR */
#ifdef MQRC_PROPERTY_NAME_TOO_BIG
ADD_MQ_REASON_TXT(MQRC_PROPERTY_NAME_TOO_BIG, "On an MQINQMP call, WebSphere MQ attempted to copy the name of the inquired property into the location indicated by the ReturnedName field of the InqPropOpts parameter but the buffer was too small to contain the full property name."); /* 2465 */
#endif /* MQRC_PROPERTY_NAME_TOO_BIG */
#ifdef MQRC_PROP_VALUE_NOT_CONVERTED
ADD_MQ_REASON_TXT(MQRC_PROP_VALUE_NOT_CONVERTED, "An MQINQMP call was issued with the MQIMPO_CONVERT_VALUE option specified in the InqPropOpts parameter, but an error occurred during conversion of the value of the property."); /* 2466 */
#endif /* MQRC_PROP_VALUE_NOT_CONVERTED */
#ifdef MQRC_PROP_TYPE_NOT_SUPPORTED
ADD_MQ_REASON_TXT(MQRC_PROP_TYPE_NOT_SUPPORTED, "An MQINQMP call was issued and the property inquired has an unsupported data type."); /* 2467 */
#endif /* MQRC_PROP_TYPE_NOT_SUPPORTED */
#ifdef MQRC_PROPERTY_VALUE_TOO_BIG
ADD_MQ_REASON_TXT(MQRC_PROPERTY_VALUE_TOO_BIG, "On an MQINQMP call, the property value was too large to fit into the supplied buffer."); /* 2469 */
#endif /* MQRC_PROPERTY_VALUE_TOO_BIG */
#ifdef MQRC_PROP_CONV_NOT_SUPPORTED
ADD_MQ_REASON_TXT(MQRC_PROP_CONV_NOT_SUPPORTED, "On an MQINQMP call, the MQIMPO_CONVERT_TYPE option was specified to request that the property value be converted to the supplied data type before the call returned."); /* 2470 */
#endif /* MQRC_PROP_CONV_NOT_SUPPORTED */
#ifdef MQRC_PROPERTY_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRC_PROPERTY_NOT_AVAILABLE, "On an MQINQMP call, no property could be found that matched the specified name."); /* 2471 */
#endif /* MQRC_PROPERTY_NOT_AVAILABLE */
#ifdef MQRC_PROP_NUMBER_FORMAT_ERROR
ADD_MQ_REASON_TXT(MQRC_PROP_NUMBER_FORMAT_ERROR, "On an MQINQMP call, conversion of the property value was requested."); /* 2472 */
#endif /* MQRC_PROP_NUMBER_FORMAT_ERROR */
#ifdef MQRC_PROPERTY_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRC_PROPERTY_TYPE_ERROR, "On an MQSETMP call, the Type parameter does not specify a valid MQTYPE_* value."); /* 2473 */
#endif /* MQRC_PROPERTY_TYPE_ERROR */
#ifdef MQRC_PROPERTIES_TOO_BIG
ADD_MQ_REASON_TXT(MQRC_PROPERTIES_TOO_BIG, "An MQPUT or MQPUT1 call was issued to put a message on a queue, but the properties of the message were too large."); /* 2478 */
#endif /* MQRC_PROPERTIES_TOO_BIG */
#ifdef MQRC_PUT_NOT_RETAINED
ADD_MQ_REASON_TXT(MQRC_PUT_NOT_RETAINED, "An MQPUT or MQPUT1 call was issued to publish a message on a topic, using the MQPMO_RETAIN option, but the publication was unable to be retained."); /* 2479 */
#endif /* MQRC_PUT_NOT_RETAINED */
#ifdef MQRC_ALIAS_TARGTYPE_CHANGED
ADD_MQ_REASON_TXT(MQRC_ALIAS_TARGTYPE_CHANGED, "An MQPUT or MQPUT1 call was issed to publish a message on a topic."); /* 2480 */
#endif /* MQRC_ALIAS_TARGTYPE_CHANGED */
#ifdef MQRC_DMPO_ERROR
ADD_MQ_REASON_TXT(MQRC_DMPO_ERROR, "On an MQDLTMP call, the delete message property options structure MQDMPO is not valid."); /* 2481 */
#endif /* MQRC_DMPO_ERROR */
#ifdef MQRC_PD_ERROR
ADD_MQ_REASON_TXT(MQRC_PD_ERROR, "On an MQSETMP or MQINQMP call, the property descriptor structure MQPD is not valid."); /* 2482 */
#endif /* MQRC_PD_ERROR */
#ifdef MQRC_CALLBACK_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRC_CALLBACK_TYPE_ERROR, "An MQCB call was made with an Operation of MQOP_REGISTER with an incorrect value for CallbackType"); /* 2483 */
#endif /* MQRC_CALLBACK_TYPE_ERROR */
#ifdef MQRC_CBD_OPTIONS_ERROR
ADD_MQ_REASON_TXT(MQRC_CBD_OPTIONS_ERROR, "An MQCB call was made with an Operation of MQOP_REGISTER with an incorrect value for the Options field of the MQCBD."); /* 2484 */
#endif /* MQRC_CBD_OPTIONS_ERROR */
#ifdef MQRC_MAX_MSG_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRC_MAX_MSG_LENGTH_ERROR, "An MQCB call was made with an Operation of MQOP_REGISTER with an incorrect value for the MaxMsgLength field of the MQCBD."); /* 2485 */
#endif /* MQRC_MAX_MSG_LENGTH_ERROR */
#ifdef MQRC_CALLBACK_ROUTINE_ERROR
ADD_MQ_REASON_TXT(MQRC_CALLBACK_ROUTINE_ERROR, "An MQCB call was made with an Operation of MQOP_REGISTER failed for one of the following reasons: Both CallbackName and CallbackFunction are specified."); /* 2486 */
#endif /* MQRC_CALLBACK_ROUTINE_ERROR */
#ifdef MQRC_CALLBACK_LINK_ERROR
ADD_MQ_REASON_TXT(MQRC_CALLBACK_LINK_ERROR, "On an MQCTL call, the callback handling module (CSQBMCSM or CSQBMCSX for batch and CSQCMCSM for CICS) could not be loaded, so the adapter could not link to it."); /* 2487 */
#endif /* MQRC_CALLBACK_LINK_ERROR */
#ifdef MQRC_OPERATION_ERROR
ADD_MQ_REASON_TXT(MQRC_OPERATION_ERROR, "An MQCTL or MQCB call was made with an invalid Operation parameter."); /* 2488 */
#endif /* MQRC_OPERATION_ERROR */
#ifdef MQRC_BMHO_ERROR
ADD_MQ_REASON_TXT(MQRC_BMHO_ERROR, "On an MQBUFMH call, the buffer to message handle options structure MQBMHO is not valid."); /* 2489 */
#endif /* MQRC_BMHO_ERROR */
#ifdef MQRC_UNSUPPORTED_PROPERTY
ADD_MQ_REASON_TXT(MQRC_UNSUPPORTED_PROPERTY, "A message was found to contain a property that the queue manager does not support."); /* 2490 */
#endif /* MQRC_UNSUPPORTED_PROPERTY */
#ifdef MQRC_PROP_NAME_NOT_CONVERTED
ADD_MQ_REASON_TXT(MQRC_PROP_NAME_NOT_CONVERTED, "An MQINQMP call was issued with the MQIMPO_CONVERT_VALUE option specified in the InqPropOpts parameter, but an error occurred during conversion of the returned name of the property."); /* 2492 */
#endif /* MQRC_PROP_NAME_NOT_CONVERTED */
#ifdef MQRC_GET_ENABLED
ADD_MQ_REASON_TXT(MQRC_GET_ENABLED, "This reason code is returned to an asynchronous consumer at the time a queue that was previously inhibited for get has been re-enabled for get."); /* 2494 */
#endif /* MQRC_GET_ENABLED */
#ifdef MQRC_MODULE_NOT_FOUND
ADD_MQ_REASON_TXT(MQRC_MODULE_NOT_FOUND, "A native shared library could not be loaded."); /* 2495 */
#endif /* MQRC_MODULE_NOT_FOUND */
#ifdef MQRC_MODULE_INVALID
ADD_MQ_REASON_TXT(MQRC_MODULE_INVALID, "An MQCB call was made with an Operation of MQOP_REGISTER, specifying a CallbackName which is not a valid load module."); /* 2496 */
#endif /* MQRC_MODULE_INVALID */
#ifdef MQRC_MODULE_ENTRY_NOT_FOUND
ADD_MQ_REASON_TXT(MQRC_MODULE_ENTRY_NOT_FOUND, "An MQCB call was made with an Operation of MQOP_REGISTER and the CallbackName identifies a function name which can’t be found in the specified library."); /* 2497 */
#endif /* MQRC_MODULE_ENTRY_NOT_FOUND */
#ifdef MQRC_MIXED_CONTENT_NOT_ALLOWED
ADD_MQ_REASON_TXT(MQRC_MIXED_CONTENT_NOT_ALLOWED, "An attempt was made to set a property with mixed content."); /* 2498 */
#endif /* MQRC_MIXED_CONTENT_NOT_ALLOWED */
#ifdef MQRC_MSG_HANDLE_IN_USE
ADD_MQ_REASON_TXT(MQRC_MSG_HANDLE_IN_USE, "A message property call was called (MQCRTMH, MQDLTMH, MQSETMP, MQINQMP, MQDLTMP or MQMHBUF) specifying a message handle that is already in use on another API call."); /* 2499 */
#endif /* MQRC_MSG_HANDLE_IN_USE */
#ifdef MQRC_HCONN_ASYNC_ACTIVE
ADD_MQ_REASON_TXT(MQRC_HCONN_ASYNC_ACTIVE, "An attempt to issue an MQI call has been made while the connection is started."); /* 2500 */
#endif /* MQRC_HCONN_ASYNC_ACTIVE */
#ifdef MQRC_MHBO_ERROR
ADD_MQ_REASON_TXT(MQRC_MHBO_ERROR, "On an MQMHBUF call, the message handle to buffer options structure MQMHBO is not valid."); /* 2501 */
#endif /* MQRC_MHBO_ERROR */
#ifdef MQRC_PUBLICATION_FAILURE
ADD_MQ_REASON_TXT(MQRC_PUBLICATION_FAILURE, "An MQPUT or MQPUT1 call was issued to publish a message on a topic."); /* 2502 */
#endif /* MQRC_PUBLICATION_FAILURE */
#ifdef MQRC_SUB_INHIBITED
ADD_MQ_REASON_TXT(MQRC_SUB_INHIBITED, "MQSUB calls are currently inhibited for the topic subscribed to."); /* 2503 */
#endif /* MQRC_SUB_INHIBITED */
#ifdef MQRC_SELECTOR_ALWAYS_FALSE
ADD_MQ_REASON_TXT(MQRC_SELECTOR_ALWAYS_FALSE, "An MQOPEN, MQPUT1 or MQSUB call was issued but a selection string was specified which will never select a message"); /* 2504 */
#endif /* MQRC_SELECTOR_ALWAYS_FALSE */
#ifdef MQRC_XEPO_ERROR
ADD_MQ_REASON_TXT(MQRC_XEPO_ERROR, "On an MQXEP call, the exit options structure MQXEPO is not valid."); /* 2507 */
#endif /* MQRC_XEPO_ERROR */
#ifdef MQRC_DURABILITY_NOT_ALTERABLE
ADD_MQ_REASON_TXT(MQRC_DURABILITY_NOT_ALTERABLE, "An MQSUB call using option MQSO_ALTER was made changing the durability of the subscription."); /* 2509 */
#endif /* MQRC_DURABILITY_NOT_ALTERABLE */
#ifdef MQRC_TOPIC_NOT_ALTERABLE
ADD_MQ_REASON_TXT(MQRC_TOPIC_NOT_ALTERABLE, "An MQSUB call using option MQSO_ALTER was made changing the one or more of the fields in the MQSD that provide the topic being subscribed to."); /* 2510 */
#endif /* MQRC_TOPIC_NOT_ALTERABLE */
#ifdef MQRC_SUBLEVEL_NOT_ALTERABLE
ADD_MQ_REASON_TXT(MQRC_SUBLEVEL_NOT_ALTERABLE, "An MQSUB call using option MQSO_ALTER was made changing the SubLevel of the subscription."); /* 2512 */
#endif /* MQRC_SUBLEVEL_NOT_ALTERABLE */
#ifdef MQRC_PROPERTY_NAME_LENGTH_ERR
ADD_MQ_REASON_TXT(MQRC_PROPERTY_NAME_LENGTH_ERR, "An attempt was made to set, inquire or delete a property with an invalid name."); /* 2513 */
#endif /* MQRC_PROPERTY_NAME_LENGTH_ERR */
#ifdef MQRC_DUPLICATE_GROUP_SUB
ADD_MQ_REASON_TXT(MQRC_DUPLICATE_GROUP_SUB, "An MQSUB call using option MQSO_GROUP_SUB was made creating a new grouped subscription but, although it has a unique SubName, it matches the Full topic name of an existing subscription in the group."); /* 2514 */
#endif /* MQRC_DUPLICATE_GROUP_SUB */
#ifdef MQRC_GROUPING_NOT_ALTERABLE
ADD_MQ_REASON_TXT(MQRC_GROUPING_NOT_ALTERABLE, "An MQSUB call was made using option MQSO_ALTER on a grouped subscription, that is one made with the option MQSO_GROUP_SUB."); /* 2515 */
#endif /* MQRC_GROUPING_NOT_ALTERABLE */
#ifdef MQRC_SELECTOR_INVALID_FOR_TYPE
ADD_MQ_REASON_TXT(MQRC_SELECTOR_INVALID_FOR_TYPE, "A SelectionString may only be specified in the MQOD for an MQOPEN/MQPUT1 if the following is true: ObjectType is MQOT_Q The queue is being opened using one of the MQOO_INPUT_* open options."); /* 2516 */
#endif /* MQRC_SELECTOR_INVALID_FOR_TYPE */
#ifdef MQRC_HOBJ_QUIESCED
ADD_MQ_REASON_TXT(MQRC_HOBJ_QUIESCED, "The HOBJ has been quiesced but there are no messages in the read ahead buffer which match the current selection criteria."); /* 2517 */
#endif /* MQRC_HOBJ_QUIESCED */
#ifdef MQRC_HOBJ_QUIESCED_NO_MSGS
ADD_MQ_REASON_TXT(MQRC_HOBJ_QUIESCED_NO_MSGS, "The HOBJ has been quiesced and the read ahead buffer is now empty."); /* 2518 */
#endif /* MQRC_HOBJ_QUIESCED_NO_MSGS */
#ifdef MQRC_SELECTION_STRING_ERROR
ADD_MQ_REASON_TXT(MQRC_SELECTION_STRING_ERROR, "The SelectionString must be specified according to the description of how to use an MQCHARV structure."); /* 2519 */
#endif /* MQRC_SELECTION_STRING_ERROR */
#ifdef MQRC_RES_OBJECT_STRING_ERROR
ADD_MQ_REASON_TXT(MQRC_RES_OBJECT_STRING_ERROR, "On the MQOPEN or MQPUT1 call in the Object Descriptor MQOD, or on the MQSUB call in the Subscription Descriptor MQSD the ResObjectString field is not valid."); /* 2520 */
#endif /* MQRC_RES_OBJECT_STRING_ERROR */
#ifdef MQRC_CONNECTION_SUSPENDED
ADD_MQ_REASON_TXT(MQRC_CONNECTION_SUSPENDED, "An MQCTL call with Operation MQOP_START_WAIT has returned because the asynchronous consumption of messages has been suspended."); /* 2521 */
#endif /* MQRC_CONNECTION_SUSPENDED */
#ifdef MQRC_INVALID_DESTINATION
ADD_MQ_REASON_TXT(MQRC_INVALID_DESTINATION, "An MQSUB call failed because of a problem with the destination where publications messages are to be sent, so an object handle cannot be returned to the application and the subscription is not made."); /* 2522 */
#endif /* MQRC_INVALID_DESTINATION */
#ifdef MQRC_INVALID_SUBSCRIPTION
ADD_MQ_REASON_TXT(MQRC_INVALID_SUBSCRIPTION, "An MQSUB call using MQSO_RESUME or MQSO_ALTER failed because the subscription named is not valid for use by applications."); /* 2523 */
#endif /* MQRC_INVALID_SUBSCRIPTION */
#ifdef MQRC_SELECTOR_NOT_ALTERABLE
ADD_MQ_REASON_TXT(MQRC_SELECTOR_NOT_ALTERABLE, "An MQSUB call was issued with the MQSO_ALTER option and the MQSD contained a SelectionString."); /* 2524 */
#endif /* MQRC_SELECTOR_NOT_ALTERABLE */
#ifdef MQRC_RETAINED_MSG_Q_ERROR
ADD_MQ_REASON_TXT(MQRC_RETAINED_MSG_Q_ERROR, "An MQSUB call which did not use the MQSO_NEW_PUBLICATIONS_ONLY option, or an MQSUBRQ call, failed because the retained publications which exist for the topic string subscribed to cannot be retrieved from the SYSTEM."); /* 2525 */
#endif /* MQRC_RETAINED_MSG_Q_ERROR */
#ifdef MQRC_RETAINED_NOT_DELIVERED
ADD_MQ_REASON_TXT(MQRC_RETAINED_NOT_DELIVERED, "An MQSUB call which did not use the MQSO_NEW_PUBLICATIONS_ONLY option or an MQSUBRQ call, failed because the retained publications which exist for the topic string subscribed to cannot be delivered to the subscription destination queue and have subsequently failed to be delivered to the dead-letter queue."); /* 2526 */
#endif /* MQRC_RETAINED_NOT_DELIVERED */
#ifdef MQRC_RFH_RESTRICTED_FORMAT_ERR
ADD_MQ_REASON_TXT(MQRC_RFH_RESTRICTED_FORMAT_ERR, "A message was put to a queue containing an MQRFH2 header which included a folder with a restricted format."); /* 2527 */
#endif /* MQRC_RFH_RESTRICTED_FORMAT_ERR */
#ifdef MQRC_CONNECTION_STOPPED
ADD_MQ_REASON_TXT(MQRC_CONNECTION_STOPPED, "An MQCTL call was issued to start the asynchronous consumption of messages, but before the connection was ready to consume messages it was stopped by one of the message consumers."); /* 2528 */
#endif /* MQRC_CONNECTION_STOPPED */
#ifdef MQRC_ASYNC_UOW_CONFLICT
ADD_MQ_REASON_TXT(MQRC_ASYNC_UOW_CONFLICT, "An MQCTL call with Operation MQOP_START was issued to start the asynchronous consumption of messages, but the connection handle used already has a global unit of work outstanding."); /* 2529 */
#endif /* MQRC_ASYNC_UOW_CONFLICT */
#ifdef MQRC_ASYNC_XA_CONFLICT
ADD_MQ_REASON_TXT(MQRC_ASYNC_XA_CONFLICT, "An MQCTL call with Operation MQOP_START was issued to start the asynchronous consumption of messages, but an external XA syncpoint coordinator has already issued an xa_open call for this connection handle."); /* 2530 */
#endif /* MQRC_ASYNC_XA_CONFLICT */
#ifdef MQRC_PUBSUB_INHIBITED
ADD_MQ_REASON_TXT(MQRC_PUBSUB_INHIBITED, "MQSUB, MQOPEN, MQPUT and MQPUT1 calls are currently inhibited for all publish/subscribe topics, either by means of the queue manager attribute PSMODE or because processing of publish/subscribe state at queue manager start-up has failed, or has not yet completed."); /* 2531 */
#endif /* MQRC_PUBSUB_INHIBITED */
#ifdef MQRC_MSG_HANDLE_COPY_FAILURE
ADD_MQ_REASON_TXT(MQRC_MSG_HANDLE_COPY_FAILURE, "An MQGET call was issued specifying a valid MsgHandle in which to retrieve any properties of the message."); /* 2532 */
#endif /* MQRC_MSG_HANDLE_COPY_FAILURE */
#ifdef MQRC_DEST_CLASS_NOT_ALTERABLE
ADD_MQ_REASON_TXT(MQRC_DEST_CLASS_NOT_ALTERABLE, "An MQSUB call using option MQSO_ALTER was made changing the use of the MQSO_MANAGED option on the subscription."); /* 2533 */
#endif /* MQRC_DEST_CLASS_NOT_ALTERABLE */
#ifdef MQRC_OPERATION_NOT_ALLOWED
ADD_MQ_REASON_TXT(MQRC_OPERATION_NOT_ALLOWED, "An MQCTL call was made with an Operation that is not allowed because of the state of asynchronous consumption on the hConn is currently in."); /* 2534 */
#endif /* MQRC_OPERATION_NOT_ALLOWED */
#ifdef MQRC_ACTION_ERROR
ADD_MQ_REASON_TXT(MQRC_ACTION_ERROR, "An MQPUT call was issued, but the value of the Action field in the PutMsgOpts parameter is not a valid MQACTP_* value."); /* 2535 */
#endif /* MQRC_ACTION_ERROR */
#ifdef MQRC_CHANNEL_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRC_CHANNEL_NOT_AVAILABLE, "An MQCONN call was issued from a client to connect to a queue manager but the channel is not currently available."); /* 2537 */
#endif /* MQRC_CHANNEL_NOT_AVAILABLE */
#ifdef MQRC_HOST_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRC_HOST_NOT_AVAILABLE, "An MQCONN call was issued from a client to connect to a queue manager but the attempt to allocate a conversation to the remote system failed."); /* 2538 */
#endif /* MQRC_HOST_NOT_AVAILABLE */
#ifdef MQRC_CHANNEL_CONFIG_ERROR
ADD_MQ_REASON_TXT(MQRC_CHANNEL_CONFIG_ERROR, "An MQCONN call was issued from a client to connect to a queue manager but the attempt to establish communication failed."); /* 2539 */
#endif /* MQRC_CHANNEL_CONFIG_ERROR */
#ifdef MQRC_UNKNOWN_CHANNEL_NAME
ADD_MQ_REASON_TXT(MQRC_UNKNOWN_CHANNEL_NAME, "An MQCONN call was issued from a client to connect to a queue manager but the attempt to establish communication failed because the queue manager did not recognise the channel name."); /* 2540 */
#endif /* MQRC_UNKNOWN_CHANNEL_NAME */
#ifdef MQRC_LOOPING_PUBLICATION
ADD_MQ_REASON_TXT(MQRC_LOOPING_PUBLICATION, "A Distributed Pub/Sub topology has been configured with a combination of Pub/Sub clusters and Pub/Sub Hierarchies such that some, or all, of the queue managers have been connected in a loop."); /* 2541 */
#endif /* MQRC_LOOPING_PUBLICATION */
#ifdef MQRC_STANDBY_Q_MGR
ADD_MQ_REASON_TXT(MQRC_STANDBY_Q_MGR, "The application attempted to connect to a standby queue manager instance."); /* 2543 */
#endif /* MQRC_STANDBY_Q_MGR */
#ifdef MQRC_RECONNECTING
ADD_MQ_REASON_TXT(MQRC_RECONNECTING, "The connection has started reconnecting."); /* 2544 */
#endif /* MQRC_RECONNECTING */
#ifdef MQRC_RECONNECTED
ADD_MQ_REASON_TXT(MQRC_RECONNECTED, "The connection reconnected successfully and all handles are reinstated."); /* 2545 */
#endif /* MQRC_RECONNECTED */
#ifdef MQRC_RECONNECT_QMID_MISMATCH
ADD_MQ_REASON_TXT(MQRC_RECONNECT_QMID_MISMATCH, "A reconnectable connection specified MQCNO_RECONNECT_Q_MGR and the connection attempted to reconnect to a different queue manager."); /* 2546 */
#endif /* MQRC_RECONNECT_QMID_MISMATCH */
#ifdef MQRC_RECONNECT_INCOMPATIBLE
ADD_MQ_REASON_TXT(MQRC_RECONNECT_INCOMPATIBLE, "An MQI option is incompatible with reconnectable connections."); /* 2547 */
#endif /* MQRC_RECONNECT_INCOMPATIBLE */
#ifdef MQRC_RECONNECT_FAILED
ADD_MQ_REASON_TXT(MQRC_RECONNECT_FAILED, "After reconnecting, an error occurred while reinstating the handles for a reconnectable connection."); /* 2548 */
#endif /* MQRC_RECONNECT_FAILED */
#ifdef MQRC_CALL_INTERRUPTED
ADD_MQ_REASON_TXT(MQRC_CALL_INTERRUPTED, "MQPUT, MQPUT1, or MQCMIT was interrupted and reconnection processing cannot reestablish a definite outcome."); /* 2549 */
#endif /* MQRC_CALL_INTERRUPTED */
#ifdef MQRC_NO_SUBS_MATCHED
ADD_MQ_REASON_TXT(MQRC_NO_SUBS_MATCHED, "An MQPUT or MQPUT1 call was successful but no subscriptions matched the topic."); /* 2550 */
#endif /* MQRC_NO_SUBS_MATCHED */
#ifdef MQRC_SELECTION_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRC_SELECTION_NOT_AVAILABLE, "An MQSUB call subscribed to publications using a SelectionString."); /* 2551 */
#endif /* MQRC_SELECTION_NOT_AVAILABLE */
#ifdef MQRC_CHANNEL_SSL_WARNING
ADD_MQ_REASON_TXT(MQRC_CHANNEL_SSL_WARNING, "An SSL security event has occurred."); /* 2552 */
#endif /* MQRC_CHANNEL_SSL_WARNING */
#ifdef MQRC_OCSP_URL_ERROR
ADD_MQ_REASON_TXT(MQRC_OCSP_URL_ERROR, "The OCSPResponderURL field does not contain a correctly formatted HTTP URL."); /* 2553 */
#endif /* MQRC_OCSP_URL_ERROR */
#ifdef MQRC_CONTENT_ERROR
ADD_MQ_REASON_TXT(MQRC_CONTENT_ERROR, "An MQPUT call was issued with a message where the content could not be parsed to determine whether the message should be delivered to a subscriber with an extended message selector."); /* 2554 */
#endif /* MQRC_CONTENT_ERROR */
#ifdef MQRC_RECONNECT_Q_MGR_REQD
ADD_MQ_REASON_TXT(MQRC_RECONNECT_Q_MGR_REQD, "The MQCNO_RECONNECT_Q_MGR option is required."); /* 2555 */
#endif /* MQRC_RECONNECT_Q_MGR_REQD */
#ifdef MQRC_RECONNECT_TIMED_OUT
ADD_MQ_REASON_TXT(MQRC_RECONNECT_TIMED_OUT, "A reconnection attempt timed out."); /* 2556 */
#endif /* MQRC_RECONNECT_TIMED_OUT */
#ifdef MQRC_PUBLISH_EXIT_ERROR
ADD_MQ_REASON_TXT(MQRC_PUBLISH_EXIT_ERROR, "A publish exit function returned an invalid response code, or failed in some other way."); /* 2557 */
#endif /* MQRC_PUBLISH_EXIT_ERROR */
#ifdef MQRC_SSL_ALT_PROVIDER_REQUIRED
ADD_MQ_REASON_TXT(MQRC_SSL_ALT_PROVIDER_REQUIRED, "You specified a CipherSpec that requires an alternative SSL provider."); /* 2570 */
#endif /* MQRC_SSL_ALT_PROVIDER_REQUIRED */
#ifdef MQRCCF_CFH_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFH_TYPE_ERROR, "Type not valid."); /* 3001 */
#endif /* MQRCCF_CFH_TYPE_ERROR */
#ifdef MQRCCF_CFH_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFH_LENGTH_ERROR, "Structure length not valid."); /* 3002 */
#endif /* MQRCCF_CFH_LENGTH_ERROR */
#ifdef MQRCCF_CFH_VERSION_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFH_VERSION_ERROR, "Structure version number is not valid."); /* 3003 */
#endif /* MQRCCF_CFH_VERSION_ERROR */
#ifdef MQRCCF_CFH_MSG_SEQ_NUMBER_ERR
ADD_MQ_REASON_TXT(MQRCCF_CFH_MSG_SEQ_NUMBER_ERR, "Message sequence number not valid."); /* 3004 */
#endif /* MQRCCF_CFH_MSG_SEQ_NUMBER_ERR */
#ifdef MQRCCF_CFH_CONTROL_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFH_CONTROL_ERROR, "Control option not valid."); /* 3005 */
#endif /* MQRCCF_CFH_CONTROL_ERROR */
#ifdef MQRCCF_CFH_PARM_COUNT_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFH_PARM_COUNT_ERROR, "Parameter count not valid."); /* 3006 */
#endif /* MQRCCF_CFH_PARM_COUNT_ERROR */
#ifdef MQRCCF_CFH_COMMAND_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFH_COMMAND_ERROR, "Command identifier not valid."); /* 3007 */
#endif /* MQRCCF_CFH_COMMAND_ERROR */
#ifdef MQRCCF_COMMAND_FAILED
ADD_MQ_REASON_TXT(MQRCCF_COMMAND_FAILED, "Command failed."); /* 3008 */
#endif /* MQRCCF_COMMAND_FAILED */
#ifdef MQRCCF_CFIN_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFIN_LENGTH_ERROR, "Structure length not valid."); /* 3009 */
#endif /* MQRCCF_CFIN_LENGTH_ERROR */
#ifdef MQRCCF_CFST_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFST_LENGTH_ERROR, "Structure length not valid."); /* 3010 */
#endif /* MQRCCF_CFST_LENGTH_ERROR */
#ifdef MQRCCF_CFST_STRING_LENGTH_ERR
ADD_MQ_REASON_TXT(MQRCCF_CFST_STRING_LENGTH_ERR, "String length not valid."); /* 3011 */
#endif /* MQRCCF_CFST_STRING_LENGTH_ERR */
#ifdef MQRCCF_FORCE_VALUE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_FORCE_VALUE_ERROR, "Force value not valid."); /* 3012 */
#endif /* MQRCCF_FORCE_VALUE_ERROR */
#ifdef MQRCCF_STRUCTURE_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_STRUCTURE_TYPE_ERROR, "Structure type not valid."); /* 3013 */
#endif /* MQRCCF_STRUCTURE_TYPE_ERROR */
#ifdef MQRCCF_CFIN_PARM_ID_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFIN_PARM_ID_ERROR, "Parameter identifier is not valid."); /* 3014 */
#endif /* MQRCCF_CFIN_PARM_ID_ERROR */
#ifdef MQRCCF_CFST_PARM_ID_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFST_PARM_ID_ERROR, "Parameter identifier is not valid."); /* 3015 */
#endif /* MQRCCF_CFST_PARM_ID_ERROR */
#ifdef MQRCCF_MSG_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRCCF_MSG_LENGTH_ERROR, "Message length not valid."); /* 3016 */
#endif /* MQRCCF_MSG_LENGTH_ERROR */
#ifdef MQRCCF_CFIN_DUPLICATE_PARM
ADD_MQ_REASON_TXT(MQRCCF_CFIN_DUPLICATE_PARM, "Duplicate parameter."); /* 3017 */
#endif /* MQRCCF_CFIN_DUPLICATE_PARM */
#ifdef MQRCCF_CFST_DUPLICATE_PARM
ADD_MQ_REASON_TXT(MQRCCF_CFST_DUPLICATE_PARM, "Duplicate parameter."); /* 3018 */
#endif /* MQRCCF_CFST_DUPLICATE_PARM */
#ifdef MQRCCF_PARM_COUNT_TOO_SMALL
ADD_MQ_REASON_TXT(MQRCCF_PARM_COUNT_TOO_SMALL, "Parameter count too small."); /* 3019 */
#endif /* MQRCCF_PARM_COUNT_TOO_SMALL */
#ifdef MQRCCF_PARM_COUNT_TOO_BIG
ADD_MQ_REASON_TXT(MQRCCF_PARM_COUNT_TOO_BIG, "Parameter count too big."); /* 3020 */
#endif /* MQRCCF_PARM_COUNT_TOO_BIG */
#ifdef MQRCCF_Q_ALREADY_IN_CELL
ADD_MQ_REASON_TXT(MQRCCF_Q_ALREADY_IN_CELL, "Queue already exists in cell."); /* 3021 */
#endif /* MQRCCF_Q_ALREADY_IN_CELL */
#ifdef MQRCCF_Q_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_Q_TYPE_ERROR, "Queue type not valid."); /* 3022 */
#endif /* MQRCCF_Q_TYPE_ERROR */
#ifdef MQRCCF_MD_FORMAT_ERROR
ADD_MQ_REASON_TXT(MQRCCF_MD_FORMAT_ERROR, "Format not valid."); /* 3023 */
#endif /* MQRCCF_MD_FORMAT_ERROR */
#ifdef MQRCCF_CFSL_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFSL_LENGTH_ERROR, "Structure length not valid."); /* 3024 */
#endif /* MQRCCF_CFSL_LENGTH_ERROR */
#ifdef MQRCCF_REPLACE_VALUE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_REPLACE_VALUE_ERROR, "Replace value not valid."); /* 3025 */
#endif /* MQRCCF_REPLACE_VALUE_ERROR */
#ifdef MQRCCF_CFIL_DUPLICATE_VALUE
ADD_MQ_REASON_TXT(MQRCCF_CFIL_DUPLICATE_VALUE, "Duplicate parameter."); /* 3026 */
#endif /* MQRCCF_CFIL_DUPLICATE_VALUE */
#ifdef MQRCCF_CFIL_COUNT_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFIL_COUNT_ERROR, "Count of parameter values not valid."); /* 3027 */
#endif /* MQRCCF_CFIL_COUNT_ERROR */
#ifdef MQRCCF_CFIL_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFIL_LENGTH_ERROR, "Structure length not valid."); /* 3028 */
#endif /* MQRCCF_CFIL_LENGTH_ERROR */
#ifdef MQRCCF_MODE_VALUE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_MODE_VALUE_ERROR, "Mode value not valid."); /* 3029 */
#endif /* MQRCCF_MODE_VALUE_ERROR */
#ifdef MQRCCF_MSG_SEQ_NUMBER_ERROR
ADD_MQ_REASON_TXT(MQRCCF_MSG_SEQ_NUMBER_ERROR, "Message sequence number not valid."); /* 3030 */
#endif /* MQRCCF_MSG_SEQ_NUMBER_ERROR */
#ifdef MQRCCF_PING_DATA_COUNT_ERROR
ADD_MQ_REASON_TXT(MQRCCF_PING_DATA_COUNT_ERROR, "Data count not valid."); /* 3031 */
#endif /* MQRCCF_PING_DATA_COUNT_ERROR */
#ifdef MQRCCF_PING_DATA_COMPARE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_PING_DATA_COMPARE_ERROR, "Ping Channel command failed."); /* 3032 */
#endif /* MQRCCF_PING_DATA_COMPARE_ERROR */
#ifdef MQRCCF_CFSL_PARM_ID_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFSL_PARM_ID_ERROR, "Parameter identifier is not valid."); /* 3033 */
#endif /* MQRCCF_CFSL_PARM_ID_ERROR */
#ifdef MQRCCF_CHANNEL_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CHANNEL_TYPE_ERROR, "Channel type not valid."); /* 3034 */
#endif /* MQRCCF_CHANNEL_TYPE_ERROR */
#ifdef MQRCCF_PARM_SEQUENCE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_PARM_SEQUENCE_ERROR, "Parameter sequence not valid."); /* 3035 */
#endif /* MQRCCF_PARM_SEQUENCE_ERROR */
#ifdef MQRCCF_XMIT_PROTOCOL_TYPE_ERR
ADD_MQ_REASON_TXT(MQRCCF_XMIT_PROTOCOL_TYPE_ERR, "Transmission protocol type not valid."); /* 3036 */
#endif /* MQRCCF_XMIT_PROTOCOL_TYPE_ERR */
#ifdef MQRCCF_BATCH_SIZE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_BATCH_SIZE_ERROR, "Batch size not valid."); /* 3037 */
#endif /* MQRCCF_BATCH_SIZE_ERROR */
#ifdef MQRCCF_DISC_INT_ERROR
ADD_MQ_REASON_TXT(MQRCCF_DISC_INT_ERROR, "Disconnection interval not valid."); /* 3038 */
#endif /* MQRCCF_DISC_INT_ERROR */
#ifdef MQRCCF_SHORT_RETRY_ERROR
ADD_MQ_REASON_TXT(MQRCCF_SHORT_RETRY_ERROR, "Short retry count not valid."); /* 3039 */
#endif /* MQRCCF_SHORT_RETRY_ERROR */
#ifdef MQRCCF_SHORT_TIMER_ERROR
ADD_MQ_REASON_TXT(MQRCCF_SHORT_TIMER_ERROR, "Short timer value not valid."); /* 3040 */
#endif /* MQRCCF_SHORT_TIMER_ERROR */
#ifdef MQRCCF_LONG_RETRY_ERROR
ADD_MQ_REASON_TXT(MQRCCF_LONG_RETRY_ERROR, "Long retry count not valid."); /* 3041 */
#endif /* MQRCCF_LONG_RETRY_ERROR */
#ifdef MQRCCF_LONG_TIMER_ERROR
ADD_MQ_REASON_TXT(MQRCCF_LONG_TIMER_ERROR, "Long timer not valid."); /* 3042 */
#endif /* MQRCCF_LONG_TIMER_ERROR */
#ifdef MQRCCF_SEQ_NUMBER_WRAP_ERROR
ADD_MQ_REASON_TXT(MQRCCF_SEQ_NUMBER_WRAP_ERROR, "Sequence wrap number not valid."); /* 3043 */
#endif /* MQRCCF_SEQ_NUMBER_WRAP_ERROR */
#ifdef MQRCCF_MAX_MSG_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRCCF_MAX_MSG_LENGTH_ERROR, "Maximum message length not valid."); /* 3044 */
#endif /* MQRCCF_MAX_MSG_LENGTH_ERROR */
#ifdef MQRCCF_PUT_AUTH_ERROR
ADD_MQ_REASON_TXT(MQRCCF_PUT_AUTH_ERROR, "Put authority value not valid."); /* 3045 */
#endif /* MQRCCF_PUT_AUTH_ERROR */
#ifdef MQRCCF_PURGE_VALUE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_PURGE_VALUE_ERROR, "Purge value not valid."); /* 3046 */
#endif /* MQRCCF_PURGE_VALUE_ERROR */
#ifdef MQRCCF_CFIL_PARM_ID_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFIL_PARM_ID_ERROR, "Parameter identifier is not valid."); /* 3047 */
#endif /* MQRCCF_CFIL_PARM_ID_ERROR */
#ifdef MQRCCF_MSG_TRUNCATED
ADD_MQ_REASON_TXT(MQRCCF_MSG_TRUNCATED, "Message truncated."); /* 3048 */
#endif /* MQRCCF_MSG_TRUNCATED */
#ifdef MQRCCF_CCSID_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CCSID_ERROR, "Coded character-set identifier error."); /* 3049 */
#endif /* MQRCCF_CCSID_ERROR */
#ifdef MQRCCF_ENCODING_ERROR
ADD_MQ_REASON_TXT(MQRCCF_ENCODING_ERROR, "Encoding error."); /* 3050 */
#endif /* MQRCCF_ENCODING_ERROR */
#ifdef MQRCCF_DATA_CONV_VALUE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_DATA_CONV_VALUE_ERROR, "Data conversion value not valid."); /* 3052 */
#endif /* MQRCCF_DATA_CONV_VALUE_ERROR */
#ifdef MQRCCF_INDOUBT_VALUE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_INDOUBT_VALUE_ERROR, "In-doubt value not valid."); /* 3053 */
#endif /* MQRCCF_INDOUBT_VALUE_ERROR */
#ifdef MQRCCF_ESCAPE_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_ESCAPE_TYPE_ERROR, "Escape type not valid."); /* 3054 */
#endif /* MQRCCF_ESCAPE_TYPE_ERROR */
#ifdef MQRCCF_CHANNEL_TABLE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CHANNEL_TABLE_ERROR, "Channel table value not valid."); /* 3062 */
#endif /* MQRCCF_CHANNEL_TABLE_ERROR */
#ifdef MQRCCF_MCA_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_MCA_TYPE_ERROR, "Message channel agent type not valid."); /* 3063 */
#endif /* MQRCCF_MCA_TYPE_ERROR */
#ifdef MQRCCF_CHL_INST_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CHL_INST_TYPE_ERROR, "Channel instance type not valid."); /* 3064 */
#endif /* MQRCCF_CHL_INST_TYPE_ERROR */
#ifdef MQRCCF_CHL_STATUS_NOT_FOUND
ADD_MQ_REASON_TXT(MQRCCF_CHL_STATUS_NOT_FOUND, "Channel status not found."); /* 3065 */
#endif /* MQRCCF_CHL_STATUS_NOT_FOUND */
#ifdef MQRCCF_CFSL_DUPLICATE_PARM
ADD_MQ_REASON_TXT(MQRCCF_CFSL_DUPLICATE_PARM, "Duplicate parameter."); /* 3066 */
#endif /* MQRCCF_CFSL_DUPLICATE_PARM */
#ifdef MQRCCF_CFSL_TOTAL_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFSL_TOTAL_LENGTH_ERROR, "Total string length error."); /* 3067 */
#endif /* MQRCCF_CFSL_TOTAL_LENGTH_ERROR */
#ifdef MQRCCF_CFSL_COUNT_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFSL_COUNT_ERROR, "Name count value not valid."); /* 3068 */
#endif /* MQRCCF_CFSL_COUNT_ERROR */
#ifdef MQRCCF_CFSL_STRING_LENGTH_ERR
ADD_MQ_REASON_TXT(MQRCCF_CFSL_STRING_LENGTH_ERR, "String length not valid."); /* 3069 */
#endif /* MQRCCF_CFSL_STRING_LENGTH_ERR */
#ifdef MQRCCF_BROKER_DELETED
ADD_MQ_REASON_TXT(MQRCCF_BROKER_DELETED, "Broker has been deleted."); /* 3070 */
#endif /* MQRCCF_BROKER_DELETED */
#ifdef MQRCCF_STREAM_ERROR
ADD_MQ_REASON_TXT(MQRCCF_STREAM_ERROR, "Stream name is not valid."); /* 3071 */
#endif /* MQRCCF_STREAM_ERROR */
#ifdef MQRCCF_TOPIC_ERROR
ADD_MQ_REASON_TXT(MQRCCF_TOPIC_ERROR, "Topic name is invalid."); /* 3072 */
#endif /* MQRCCF_TOPIC_ERROR */
#ifdef MQRCCF_NOT_REGISTERED
ADD_MQ_REASON_TXT(MQRCCF_NOT_REGISTERED, "Subscriber or publisher is not registered."); /* 3073 */
#endif /* MQRCCF_NOT_REGISTERED */
#ifdef MQRCCF_Q_MGR_NAME_ERROR
ADD_MQ_REASON_TXT(MQRCCF_Q_MGR_NAME_ERROR, "An invalid or unknown queue manager name has been supplied."); /* 3074 */
#endif /* MQRCCF_Q_MGR_NAME_ERROR */
#ifdef MQRCCF_INCORRECT_STREAM
ADD_MQ_REASON_TXT(MQRCCF_INCORRECT_STREAM, "Stream name does not match the stream queue it was sent to."); /* 3075 */
#endif /* MQRCCF_INCORRECT_STREAM */
#ifdef MQRCCF_Q_NAME_ERROR
ADD_MQ_REASON_TXT(MQRCCF_Q_NAME_ERROR, "An invalid or unknown queue name has been supplied."); /* 3076 */
#endif /* MQRCCF_Q_NAME_ERROR */
#ifdef MQRCCF_NO_RETAINED_MSG
ADD_MQ_REASON_TXT(MQRCCF_NO_RETAINED_MSG, "No retained message exists for the topic specified."); /* 3077 */
#endif /* MQRCCF_NO_RETAINED_MSG */
#ifdef MQRCCF_DUPLICATE_IDENTITY
ADD_MQ_REASON_TXT(MQRCCF_DUPLICATE_IDENTITY, "Publisher or subscriber identity already assigned to another user ID."); /* 3078 */
#endif /* MQRCCF_DUPLICATE_IDENTITY */
#ifdef MQRCCF_INCORRECT_Q
ADD_MQ_REASON_TXT(MQRCCF_INCORRECT_Q, "Command sent to wrong broker queue."); /* 3079 */
#endif /* MQRCCF_INCORRECT_Q */
#ifdef MQRCCF_CORREL_ID_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CORREL_ID_ERROR, "Correlation identifier used as part of an identity is all binary zeroes."); /* 3080 */
#endif /* MQRCCF_CORREL_ID_ERROR */
#ifdef MQRCCF_NOT_AUTHORIZED
ADD_MQ_REASON_TXT(MQRCCF_NOT_AUTHORIZED, "Subscriber has insufficient authority."); /* 3081 */
#endif /* MQRCCF_NOT_AUTHORIZED */
#ifdef MQRCCF_UNKNOWN_STREAM
ADD_MQ_REASON_TXT(MQRCCF_UNKNOWN_STREAM, "Stream is not known by the broker or could not be created."); /* 3082 */
#endif /* MQRCCF_UNKNOWN_STREAM */
#ifdef MQRCCF_REG_OPTIONS_ERROR
ADD_MQ_REASON_TXT(MQRCCF_REG_OPTIONS_ERROR, "Invalid registration options have been supplied."); /* 3083 */
#endif /* MQRCCF_REG_OPTIONS_ERROR */
#ifdef MQRCCF_PUB_OPTIONS_ERROR
ADD_MQ_REASON_TXT(MQRCCF_PUB_OPTIONS_ERROR, "Invalid publication options have been supplied."); /* 3084 */
#endif /* MQRCCF_PUB_OPTIONS_ERROR */
#ifdef MQRCCF_UNKNOWN_BROKER
ADD_MQ_REASON_TXT(MQRCCF_UNKNOWN_BROKER, "Command received from an unknown broker."); /* 3085 */
#endif /* MQRCCF_UNKNOWN_BROKER */
#ifdef MQRCCF_Q_MGR_CCSID_ERROR
ADD_MQ_REASON_TXT(MQRCCF_Q_MGR_CCSID_ERROR, "Queue manager coded character set identifier error."); /* 3086 */
#endif /* MQRCCF_Q_MGR_CCSID_ERROR */
#ifdef MQRCCF_DEL_OPTIONS_ERROR
ADD_MQ_REASON_TXT(MQRCCF_DEL_OPTIONS_ERROR, "Invalid delete options have been supplied."); /* 3087 */
#endif /* MQRCCF_DEL_OPTIONS_ERROR */
#ifdef MQRCCF_CLUSTER_NAME_CONFLICT
ADD_MQ_REASON_TXT(MQRCCF_CLUSTER_NAME_CONFLICT, "ClusterName and ClusterNamelist attributes conflict."); /* 3088 */
#endif /* MQRCCF_CLUSTER_NAME_CONFLICT */
#ifdef MQRCCF_REPOS_NAME_CONFLICT
ADD_MQ_REASON_TXT(MQRCCF_REPOS_NAME_CONFLICT, "RepositoryName and RepositoryNamelist attributes conflict."); /* 3089 */
#endif /* MQRCCF_REPOS_NAME_CONFLICT */
#ifdef MQRCCF_CLUSTER_Q_USAGE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CLUSTER_Q_USAGE_ERROR, "Cluster queue cannot be a transmission queue."); /* 3090 */
#endif /* MQRCCF_CLUSTER_Q_USAGE_ERROR */
#ifdef MQRCCF_ACTION_VALUE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_ACTION_VALUE_ERROR, "Action value not valid."); /* 3091 */
#endif /* MQRCCF_ACTION_VALUE_ERROR */
#ifdef MQRCCF_COMMS_LIBRARY_ERROR
ADD_MQ_REASON_TXT(MQRCCF_COMMS_LIBRARY_ERROR, "Library for requested communications protocol could not be loaded."); /* 3092 */
#endif /* MQRCCF_COMMS_LIBRARY_ERROR */
#ifdef MQRCCF_NETBIOS_NAME_ERROR
ADD_MQ_REASON_TXT(MQRCCF_NETBIOS_NAME_ERROR, "NetBIOS listener name not defined."); /* 3093 */
#endif /* MQRCCF_NETBIOS_NAME_ERROR */
#ifdef MQRCCF_BROKER_COMMAND_FAILED
ADD_MQ_REASON_TXT(MQRCCF_BROKER_COMMAND_FAILED, "The broker command failed to complete."); /* 3094 */
#endif /* MQRCCF_BROKER_COMMAND_FAILED */
#ifdef MQRCCF_CFST_CONFLICTING_PARM
ADD_MQ_REASON_TXT(MQRCCF_CFST_CONFLICTING_PARM, "Conflicting parameters."); /* 3095 */
#endif /* MQRCCF_CFST_CONFLICTING_PARM */
#ifdef MQRCCF_PATH_NOT_VALID
ADD_MQ_REASON_TXT(MQRCCF_PATH_NOT_VALID, "Path not valid."); /* 3096 */
#endif /* MQRCCF_PATH_NOT_VALID */
#ifdef MQRCCF_PARM_SYNTAX_ERROR
ADD_MQ_REASON_TXT(MQRCCF_PARM_SYNTAX_ERROR, "Syntax error found in parameter."); /* 3097 */
#endif /* MQRCCF_PARM_SYNTAX_ERROR */
#ifdef MQRCCF_PWD_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRCCF_PWD_LENGTH_ERROR, "Password length error."); /* 3098 */
#endif /* MQRCCF_PWD_LENGTH_ERROR */
#ifdef MQRCCF_FILTER_ERROR
ADD_MQ_REASON_TXT(MQRCCF_FILTER_ERROR, "Content based filter expression not valid."); /* 3150 */
#endif /* MQRCCF_FILTER_ERROR */
#ifdef MQRCCF_WRONG_USER
ADD_MQ_REASON_TXT(MQRCCF_WRONG_USER, "Wrong user."); /* 3151 */
#endif /* MQRCCF_WRONG_USER */
#ifdef MQRCCF_DUPLICATE_SUBSCRIPTION
ADD_MQ_REASON_TXT(MQRCCF_DUPLICATE_SUBSCRIPTION, "The subscription already exists."); /* 3152 */
#endif /* MQRCCF_DUPLICATE_SUBSCRIPTION */
#ifdef MQRCCF_SUB_NAME_ERROR
ADD_MQ_REASON_TXT(MQRCCF_SUB_NAME_ERROR, "The subscription name parameter is in error."); /* 3153 */
#endif /* MQRCCF_SUB_NAME_ERROR */
#ifdef MQRCCF_SUB_IDENTITY_ERROR
ADD_MQ_REASON_TXT(MQRCCF_SUB_IDENTITY_ERROR, "The subscription identity parameter is in error."); /* 3154 */
#endif /* MQRCCF_SUB_IDENTITY_ERROR */
#ifdef MQRCCF_SUBSCRIPTION_IN_USE
ADD_MQ_REASON_TXT(MQRCCF_SUBSCRIPTION_IN_USE, "The subscription is in use."); /* 3155 */
#endif /* MQRCCF_SUBSCRIPTION_IN_USE */
#ifdef MQRCCF_SUBSCRIPTION_LOCKED
ADD_MQ_REASON_TXT(MQRCCF_SUBSCRIPTION_LOCKED, "The subscription is locked."); /* 3156 */
#endif /* MQRCCF_SUBSCRIPTION_LOCKED */
#ifdef MQRCCF_ALREADY_JOINED
ADD_MQ_REASON_TXT(MQRCCF_ALREADY_JOINED, "The identity already has an entry for this subscription."); /* 3157 */
#endif /* MQRCCF_ALREADY_JOINED */
#ifdef MQRCCF_OBJECT_IN_USE
ADD_MQ_REASON_TXT(MQRCCF_OBJECT_IN_USE, "Object in use by another command."); /* 3160 */
#endif /* MQRCCF_OBJECT_IN_USE */
#ifdef MQRCCF_UNKNOWN_FILE_NAME
ADD_MQ_REASON_TXT(MQRCCF_UNKNOWN_FILE_NAME, "File not defined to CICS."); /* 3161 */
#endif /* MQRCCF_UNKNOWN_FILE_NAME */
#ifdef MQRCCF_FILE_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRCCF_FILE_NOT_AVAILABLE, "File not available to CICS."); /* 3162 */
#endif /* MQRCCF_FILE_NOT_AVAILABLE */
#ifdef MQRCCF_DISC_RETRY_ERROR
ADD_MQ_REASON_TXT(MQRCCF_DISC_RETRY_ERROR, "Disconnection retry count not valid."); /* 3163 */
#endif /* MQRCCF_DISC_RETRY_ERROR */
#ifdef MQRCCF_ALLOC_RETRY_ERROR
ADD_MQ_REASON_TXT(MQRCCF_ALLOC_RETRY_ERROR, "Allocation retry count not valid."); /* 3164 */
#endif /* MQRCCF_ALLOC_RETRY_ERROR */
#ifdef MQRCCF_ALLOC_SLOW_TIMER_ERROR
ADD_MQ_REASON_TXT(MQRCCF_ALLOC_SLOW_TIMER_ERROR, "Allocation slow retry timer value not valid."); /* 3165 */
#endif /* MQRCCF_ALLOC_SLOW_TIMER_ERROR */
#ifdef MQRCCF_ALLOC_FAST_TIMER_ERROR
ADD_MQ_REASON_TXT(MQRCCF_ALLOC_FAST_TIMER_ERROR, "Allocation fast retry timer value not valid."); /* 3166 */
#endif /* MQRCCF_ALLOC_FAST_TIMER_ERROR */
#ifdef MQRCCF_PORT_NUMBER_ERROR
ADD_MQ_REASON_TXT(MQRCCF_PORT_NUMBER_ERROR, "Port number value not valid."); /* 3167 */
#endif /* MQRCCF_PORT_NUMBER_ERROR */
#ifdef MQRCCF_CHL_SYSTEM_NOT_ACTIVE
ADD_MQ_REASON_TXT(MQRCCF_CHL_SYSTEM_NOT_ACTIVE, "Channel system is not active."); /* 3168 */
#endif /* MQRCCF_CHL_SYSTEM_NOT_ACTIVE */
#ifdef MQRCCF_ENTITY_NAME_MISSING
ADD_MQ_REASON_TXT(MQRCCF_ENTITY_NAME_MISSING, "Entity name required but missing."); /* 3169 */
#endif /* MQRCCF_ENTITY_NAME_MISSING */
#ifdef MQRCCF_PROFILE_NAME_ERROR
ADD_MQ_REASON_TXT(MQRCCF_PROFILE_NAME_ERROR, "Profile name not valid."); /* 3170 */
#endif /* MQRCCF_PROFILE_NAME_ERROR */
#ifdef MQRCCF_AUTH_VALUE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_AUTH_VALUE_ERROR, "Authorization value not valid."); /* 3171 */
#endif /* MQRCCF_AUTH_VALUE_ERROR */
#ifdef MQRCCF_AUTH_VALUE_MISSING
ADD_MQ_REASON_TXT(MQRCCF_AUTH_VALUE_MISSING, "Authorization value required but missing."); /* 3172 */
#endif /* MQRCCF_AUTH_VALUE_MISSING */
#ifdef MQRCCF_OBJECT_TYPE_MISSING
ADD_MQ_REASON_TXT(MQRCCF_OBJECT_TYPE_MISSING, "Object type value required but missing."); /* 3173 */
#endif /* MQRCCF_OBJECT_TYPE_MISSING */
#ifdef MQRCCF_CONNECTION_ID_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CONNECTION_ID_ERROR, "Error in connection id parameter."); /* 3174 */
#endif /* MQRCCF_CONNECTION_ID_ERROR */
#ifdef MQRCCF_LOG_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_LOG_TYPE_ERROR, "Log type not valid."); /* 3175 */
#endif /* MQRCCF_LOG_TYPE_ERROR */
#ifdef MQRCCF_PROGRAM_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRCCF_PROGRAM_NOT_AVAILABLE, "Program not available."); /* 3176 */
#endif /* MQRCCF_PROGRAM_NOT_AVAILABLE */
#ifdef MQRCCF_PROGRAM_AUTH_FAILED
ADD_MQ_REASON_TXT(MQRCCF_PROGRAM_AUTH_FAILED, "Program not available."); /* 3177 */
#endif /* MQRCCF_PROGRAM_AUTH_FAILED */
#ifdef MQRCCF_NONE_FOUND
ADD_MQ_REASON_TXT(MQRCCF_NONE_FOUND, "No items found matching request criteria."); /* 3200 */
#endif /* MQRCCF_NONE_FOUND */
#ifdef MQRCCF_SECURITY_SWITCH_OFF
ADD_MQ_REASON_TXT(MQRCCF_SECURITY_SWITCH_OFF, "Security refresh or reverification not processed, security switch set OFF."); /* 3201 */
#endif /* MQRCCF_SECURITY_SWITCH_OFF */
#ifdef MQRCCF_SECURITY_REFRESH_FAILED
ADD_MQ_REASON_TXT(MQRCCF_SECURITY_REFRESH_FAILED, "Security refresh did not take place."); /* 3202 */
#endif /* MQRCCF_SECURITY_REFRESH_FAILED */
#ifdef MQRCCF_PARM_CONFLICT
ADD_MQ_REASON_TXT(MQRCCF_PARM_CONFLICT, "Incompatible parameters or parameter values."); /* 3203 */
#endif /* MQRCCF_PARM_CONFLICT */
#ifdef MQRCCF_COMMAND_INHIBITED
ADD_MQ_REASON_TXT(MQRCCF_COMMAND_INHIBITED, "Commands not allowed at present time."); /* 3204 */
#endif /* MQRCCF_COMMAND_INHIBITED */
#ifdef MQRCCF_OBJECT_BEING_DELETED
ADD_MQ_REASON_TXT(MQRCCF_OBJECT_BEING_DELETED, "Object is being deleted."); /* 3205 */
#endif /* MQRCCF_OBJECT_BEING_DELETED */
#ifdef MQRCCF_STORAGE_CLASS_IN_USE
ADD_MQ_REASON_TXT(MQRCCF_STORAGE_CLASS_IN_USE, "Storage class is active or queue is in use."); /* 3207 */
#endif /* MQRCCF_STORAGE_CLASS_IN_USE */
#ifdef MQRCCF_OBJECT_NAME_RESTRICTED
ADD_MQ_REASON_TXT(MQRCCF_OBJECT_NAME_RESTRICTED, "Incompatible object name and type."); /* 3208 */
#endif /* MQRCCF_OBJECT_NAME_RESTRICTED */
#ifdef MQRCCF_OBJECT_LIMIT_EXCEEDED
ADD_MQ_REASON_TXT(MQRCCF_OBJECT_LIMIT_EXCEEDED, "Local queue limit exceeded."); /* 3209 */
#endif /* MQRCCF_OBJECT_LIMIT_EXCEEDED */
#ifdef MQRCCF_OBJECT_OPEN_FORCE
ADD_MQ_REASON_TXT(MQRCCF_OBJECT_OPEN_FORCE, "Object is in use, but could be changed specifying Force as MQFC_YES."); /* 3210 */
#endif /* MQRCCF_OBJECT_OPEN_FORCE */
#ifdef MQRCCF_DISPOSITION_CONFLICT
ADD_MQ_REASON_TXT(MQRCCF_DISPOSITION_CONFLICT, "Parameters are incompatible with disposition."); /* 3211 */
#endif /* MQRCCF_DISPOSITION_CONFLICT */
#ifdef MQRCCF_Q_MGR_NOT_IN_QSG
ADD_MQ_REASON_TXT(MQRCCF_Q_MGR_NOT_IN_QSG, "Queue manager is not in a queue-sharing group."); /* 3212 */
#endif /* MQRCCF_Q_MGR_NOT_IN_QSG */
#ifdef MQRCCF_ATTR_VALUE_FIXED
ADD_MQ_REASON_TXT(MQRCCF_ATTR_VALUE_FIXED, "Parameter value cannot be changed."); /* 3213 */
#endif /* MQRCCF_ATTR_VALUE_FIXED */
#ifdef MQRCCF_NAMELIST_ERROR
ADD_MQ_REASON_TXT(MQRCCF_NAMELIST_ERROR, "Namelist is empty or wrong type."); /* 3215 */
#endif /* MQRCCF_NAMELIST_ERROR */
#ifdef MQRCCF_NO_CHANNEL_INITIATOR
ADD_MQ_REASON_TXT(MQRCCF_NO_CHANNEL_INITIATOR, "Channel initiator not active."); /* 3217 */
#endif /* MQRCCF_NO_CHANNEL_INITIATOR */
#ifdef MQRCCF_CHANNEL_INITIATOR_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CHANNEL_INITIATOR_ERROR, "Channel initiator cannot be started, or no suitable channel initiator is available."); /* 3218 */
#endif /* MQRCCF_CHANNEL_INITIATOR_ERROR */
#ifdef MQRCCF_COMMAND_LEVEL_CONFLICT
ADD_MQ_REASON_TXT(MQRCCF_COMMAND_LEVEL_CONFLICT, "Incompatible queue manager command levels."); /* 3222 */
#endif /* MQRCCF_COMMAND_LEVEL_CONFLICT */
#ifdef MQRCCF_Q_ATTR_CONFLICT
ADD_MQ_REASON_TXT(MQRCCF_Q_ATTR_CONFLICT, "Queue attributes are incompatible."); /* 3223 */
#endif /* MQRCCF_Q_ATTR_CONFLICT */
#ifdef MQRCCF_EVENTS_DISABLED
ADD_MQ_REASON_TXT(MQRCCF_EVENTS_DISABLED, "Events not enabled."); /* 3224 */
#endif /* MQRCCF_EVENTS_DISABLED */
#ifdef MQRCCF_COMMAND_SCOPE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_COMMAND_SCOPE_ERROR, "Queue-sharing group error."); /* 3225 */
#endif /* MQRCCF_COMMAND_SCOPE_ERROR */
#ifdef MQRCCF_COMMAND_REPLY_ERROR
ADD_MQ_REASON_TXT(MQRCCF_COMMAND_REPLY_ERROR, "Error saving command reply information."); /* 3226 */
#endif /* MQRCCF_COMMAND_REPLY_ERROR */
#ifdef MQRCCF_FUNCTION_RESTRICTED
ADD_MQ_REASON_TXT(MQRCCF_FUNCTION_RESTRICTED, "Restricted command or parameter value used."); /* 3227 */
#endif /* MQRCCF_FUNCTION_RESTRICTED */
#ifdef MQRCCF_PARM_MISSING
ADD_MQ_REASON_TXT(MQRCCF_PARM_MISSING, "Required parameter not specified."); /* 3228 */
#endif /* MQRCCF_PARM_MISSING */
#ifdef MQRCCF_PARM_VALUE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_PARM_VALUE_ERROR, "Parameter value invalid."); /* 3229 */
#endif /* MQRCCF_PARM_VALUE_ERROR */
#ifdef MQRCCF_COMMAND_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRCCF_COMMAND_LENGTH_ERROR, "Command exceeds allowable length."); /* 3230 */
#endif /* MQRCCF_COMMAND_LENGTH_ERROR */
#ifdef MQRCCF_COMMAND_ORIGIN_ERROR
ADD_MQ_REASON_TXT(MQRCCF_COMMAND_ORIGIN_ERROR, "Command issued incorrectly."); /* 3231 */
#endif /* MQRCCF_COMMAND_ORIGIN_ERROR */
#ifdef MQRCCF_LISTENER_CONFLICT
ADD_MQ_REASON_TXT(MQRCCF_LISTENER_CONFLICT, "Address conflict for listener."); /* 3232 */
#endif /* MQRCCF_LISTENER_CONFLICT */
#ifdef MQRCCF_LISTENER_STARTED
ADD_MQ_REASON_TXT(MQRCCF_LISTENER_STARTED, "Listener is started."); /* 3233 */
#endif /* MQRCCF_LISTENER_STARTED */
#ifdef MQRCCF_LISTENER_STOPPED
ADD_MQ_REASON_TXT(MQRCCF_LISTENER_STOPPED, "Listener is stopped."); /* 3234 */
#endif /* MQRCCF_LISTENER_STOPPED */
#ifdef MQRCCF_CHANNEL_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CHANNEL_ERROR, "Channel command failed."); /* 3235 */
#endif /* MQRCCF_CHANNEL_ERROR */
#ifdef MQRCCF_CF_STRUC_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CF_STRUC_ERROR, "CF structure error."); /* 3236 */
#endif /* MQRCCF_CF_STRUC_ERROR */
#ifdef MQRCCF_UNKNOWN_USER_ID
ADD_MQ_REASON_TXT(MQRCCF_UNKNOWN_USER_ID, "User identifier not found."); /* 3237 */
#endif /* MQRCCF_UNKNOWN_USER_ID */
#ifdef MQRCCF_UNEXPECTED_ERROR
ADD_MQ_REASON_TXT(MQRCCF_UNEXPECTED_ERROR, "Unexpected or severe error."); /* 3238 */
#endif /* MQRCCF_UNEXPECTED_ERROR */
#ifdef MQRCCF_NO_XCF_PARTNER
ADD_MQ_REASON_TXT(MQRCCF_NO_XCF_PARTNER, "MQ is not connected to the XCF partner."); /* 3239 */
#endif /* MQRCCF_NO_XCF_PARTNER */
#ifdef MQRCCF_CFGR_PARM_ID_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFGR_PARM_ID_ERROR, "Parameter identifier is not valid."); /* 3240 */
#endif /* MQRCCF_CFGR_PARM_ID_ERROR */
#ifdef MQRCCF_CFIF_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFIF_LENGTH_ERROR, "Structure length not valid."); /* 3241 */
#endif /* MQRCCF_CFIF_LENGTH_ERROR */
#ifdef MQRCCF_CFIF_OPERATOR_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFIF_OPERATOR_ERROR, "Parameter count not valid."); /* 3242 */
#endif /* MQRCCF_CFIF_OPERATOR_ERROR */
#ifdef MQRCCF_CFIF_PARM_ID_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFIF_PARM_ID_ERROR, "Parameter identifier is not valid."); /* 3243 */
#endif /* MQRCCF_CFIF_PARM_ID_ERROR */
#ifdef MQRCCF_CFSF_FILTER_VAL_LEN_ERR
ADD_MQ_REASON_TXT(MQRCCF_CFSF_FILTER_VAL_LEN_ERR, "Filter value length not valid."); /* 3244 */
#endif /* MQRCCF_CFSF_FILTER_VAL_LEN_ERR */
#ifdef MQRCCF_CFSF_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFSF_LENGTH_ERROR, "Structure length not valid."); /* 3245 */
#endif /* MQRCCF_CFSF_LENGTH_ERROR */
#ifdef MQRCCF_CFSF_OPERATOR_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFSF_OPERATOR_ERROR, "Parameter count not valid."); /* 3246 */
#endif /* MQRCCF_CFSF_OPERATOR_ERROR */
#ifdef MQRCCF_CFSF_PARM_ID_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFSF_PARM_ID_ERROR, "Parameter identifier is not valid."); /* 3247 */
#endif /* MQRCCF_CFSF_PARM_ID_ERROR */
#ifdef MQRCCF_TOO_MANY_FILTERS
ADD_MQ_REASON_TXT(MQRCCF_TOO_MANY_FILTERS, "Too many filters."); /* 3248 */
#endif /* MQRCCF_TOO_MANY_FILTERS */
#ifdef MQRCCF_LISTENER_RUNNING
ADD_MQ_REASON_TXT(MQRCCF_LISTENER_RUNNING, "Listener is running."); /* 3249 */
#endif /* MQRCCF_LISTENER_RUNNING */
#ifdef MQRCCF_LSTR_STATUS_NOT_FOUND
ADD_MQ_REASON_TXT(MQRCCF_LSTR_STATUS_NOT_FOUND, "Listener status not found."); /* 3250 */
#endif /* MQRCCF_LSTR_STATUS_NOT_FOUND */
#ifdef MQRCCF_SERVICE_RUNNING
ADD_MQ_REASON_TXT(MQRCCF_SERVICE_RUNNING, "Service is running."); /* 3251 */
#endif /* MQRCCF_SERVICE_RUNNING */
#ifdef MQRCCF_SERV_STATUS_NOT_FOUND
ADD_MQ_REASON_TXT(MQRCCF_SERV_STATUS_NOT_FOUND, "Service status not found."); /* 3252 */
#endif /* MQRCCF_SERV_STATUS_NOT_FOUND */
#ifdef MQRCCF_SERVICE_STOPPED
ADD_MQ_REASON_TXT(MQRCCF_SERVICE_STOPPED, "Service is stopped."); /* 3253 */
#endif /* MQRCCF_SERVICE_STOPPED */
#ifdef MQRCCF_CFBS_DUPLICATE_PARM
ADD_MQ_REASON_TXT(MQRCCF_CFBS_DUPLICATE_PARM, "Duplicate parameter."); /* 3254 */
#endif /* MQRCCF_CFBS_DUPLICATE_PARM */
#ifdef MQRCCF_CFBS_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFBS_LENGTH_ERROR, "Structure length not valid."); /* 3255 */
#endif /* MQRCCF_CFBS_LENGTH_ERROR */
#ifdef MQRCCF_CFBS_PARM_ID_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFBS_PARM_ID_ERROR, "Parameter identifier is not valid."); /* 3256 */
#endif /* MQRCCF_CFBS_PARM_ID_ERROR */
#ifdef MQRCCF_CFBS_STRING_LENGTH_ERR
ADD_MQ_REASON_TXT(MQRCCF_CFBS_STRING_LENGTH_ERR, "String length not valid."); /* 3257 */
#endif /* MQRCCF_CFBS_STRING_LENGTH_ERR */
#ifdef MQRCCF_CFGR_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFGR_LENGTH_ERROR, "Structure length not valid."); /* 3258 */
#endif /* MQRCCF_CFGR_LENGTH_ERROR */
#ifdef MQRCCF_CFGR_PARM_COUNT_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFGR_PARM_COUNT_ERROR, "Parameter count not valid."); /* 3259 */
#endif /* MQRCCF_CFGR_PARM_COUNT_ERROR */
#ifdef MQRCCF_CONN_NOT_STOPPED
ADD_MQ_REASON_TXT(MQRCCF_CONN_NOT_STOPPED, "Connection not stopped."); /* 3260 */
#endif /* MQRCCF_CONN_NOT_STOPPED */
#ifdef MQRCCF_SERVICE_REQUEST_PENDING
ADD_MQ_REASON_TXT(MQRCCF_SERVICE_REQUEST_PENDING, "A Suspend or Resume Queue Manager command was issued, or a Refresh Security command, but such a command is currently in progress."); /* 3261 */
#endif /* MQRCCF_SERVICE_REQUEST_PENDING */
#ifdef MQRCCF_NO_START_CMD
ADD_MQ_REASON_TXT(MQRCCF_NO_START_CMD, "No start command."); /* 3262 */
#endif /* MQRCCF_NO_START_CMD */
#ifdef MQRCCF_NO_STOP_CMD
ADD_MQ_REASON_TXT(MQRCCF_NO_STOP_CMD, "No stop command."); /* 3263 */
#endif /* MQRCCF_NO_STOP_CMD */
#ifdef MQRCCF_CFBF_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFBF_LENGTH_ERROR, "Structure length not valid."); /* 3264 */
#endif /* MQRCCF_CFBF_LENGTH_ERROR */
#ifdef MQRCCF_CFBF_PARM_ID_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFBF_PARM_ID_ERROR, "Parameter identifier is not valid."); /* 3265 */
#endif /* MQRCCF_CFBF_PARM_ID_ERROR */
#ifdef MQRCCF_CFBF_FILTER_VAL_LEN_ERR
ADD_MQ_REASON_TXT(MQRCCF_CFBF_FILTER_VAL_LEN_ERR, "Filter value length not valid."); /* 3266 */
#endif /* MQRCCF_CFBF_FILTER_VAL_LEN_ERR */
#ifdef MQRCCF_CFBF_OPERATOR_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CFBF_OPERATOR_ERROR, "Parameter count not valid."); /* 3267 */
#endif /* MQRCCF_CFBF_OPERATOR_ERROR */
#ifdef MQRCCF_LISTENER_STILL_ACTIVE
ADD_MQ_REASON_TXT(MQRCCF_LISTENER_STILL_ACTIVE, "Listener still active."); /* 3268 */
#endif /* MQRCCF_LISTENER_STILL_ACTIVE */
#ifdef MQRCCF_TOPICSTR_ALREADY_EXISTS
ADD_MQ_REASON_TXT(MQRCCF_TOPICSTR_ALREADY_EXISTS, "The topic string specified already exists in another topic object."); /* 3300 */
#endif /* MQRCCF_TOPICSTR_ALREADY_EXISTS */
#ifdef MQRCCF_SHARING_CONVS_ERROR
ADD_MQ_REASON_TXT(MQRCCF_SHARING_CONVS_ERROR, "An invalid value has been given for SharingConversations parameter in the Channel definition Programmer responseCorrect the value used in the PCF SharingConversations (MQCFIN) parameter."); /* 3301 */
#endif /* MQRCCF_SHARING_CONVS_ERROR */
#ifdef MQRCCF_SHARING_CONVS_TYPE
ADD_MQ_REASON_TXT(MQRCCF_SHARING_CONVS_TYPE, "SharingConversations parameter is not allowed for this channel type."); /* 3302 */
#endif /* MQRCCF_SHARING_CONVS_TYPE */
#ifdef MQRCCF_SECURITY_CASE_CONFLICT
ADD_MQ_REASON_TXT(MQRCCF_SECURITY_CASE_CONFLICT, "A Refresh Security PCF command was issued, but the case currently in use differs from the system setting and if refreshed would result in the set of classes using different case settings."); /* 3303 */
#endif /* MQRCCF_SECURITY_CASE_CONFLICT */
#ifdef MQRCCF_TOPIC_TYPE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_TOPIC_TYPE_ERROR, "An Inquire or Delete Topic PCF command was issued with an invalid TopicType parameter."); /* 3305 */
#endif /* MQRCCF_TOPIC_TYPE_ERROR */
#ifdef MQRCCF_MAX_INSTANCES_ERROR
ADD_MQ_REASON_TXT(MQRCCF_MAX_INSTANCES_ERROR, "An invalid value was given for the maximum number of simultaneous instances of a server-connection channel (MaxInstances) for the channel definition."); /* 3306 */
#endif /* MQRCCF_MAX_INSTANCES_ERROR */
#ifdef MQRCCF_MAX_INSTS_PER_CLNT_ERR
ADD_MQ_REASON_TXT(MQRCCF_MAX_INSTS_PER_CLNT_ERR, "An invalid value was given for the MaxInstancesPerClient property."); /* 3307 */
#endif /* MQRCCF_MAX_INSTS_PER_CLNT_ERR */
#ifdef MQRCCF_TOPIC_STRING_NOT_FOUND
ADD_MQ_REASON_TXT(MQRCCF_TOPIC_STRING_NOT_FOUND, "When processing an Inquire Topic Status command, the topic string specified did not match any topic nodes in the topic tree."); /* 3308 */
#endif /* MQRCCF_TOPIC_STRING_NOT_FOUND */
#ifdef MQRCCF_SUBSCRIPTION_POINT_ERR
ADD_MQ_REASON_TXT(MQRCCF_SUBSCRIPTION_POINT_ERR, "The Subscription point was not valid."); /* 3309 */
#endif /* MQRCCF_SUBSCRIPTION_POINT_ERR */
#ifdef MQRCCF_SUB_ALREADY_EXISTS
ADD_MQ_REASON_TXT(MQRCCF_SUB_ALREADY_EXISTS, "An MQSUB call was issued to create a subscription, using the MQSO_CREATE option."); /* 3311 */
#endif /* MQRCCF_SUB_ALREADY_EXISTS */
#ifdef MQRCCF_INVALID_DESTINATION
ADD_MQ_REASON_TXT(MQRCCF_INVALID_DESTINATION, "The Subscription or Topic object used in a Change, Copy, Create or Delete PCF command is invalid."); /* 3317 */
#endif /* MQRCCF_INVALID_DESTINATION */
#ifdef MQRCCF_PUBSUB_INHIBITED
ADD_MQ_REASON_TXT(MQRCCF_PUBSUB_INHIBITED, "MQSUB, MQOPEN, MQPUT and MQPUT1 calls are currently inhibited for all publish/subscribe topics, either by means of the queue manager attribute PSMODE or because processing of publish/subscribe state at queue manager start-up has failed, or has not yet completed."); /* 3318 */
#endif /* MQRCCF_PUBSUB_INHIBITED */
#ifdef MQRCCF_SSL_ALT_PROVIDER_REQD
ADD_MQ_REASON_TXT(MQRCCF_SSL_ALT_PROVIDER_REQD, "You specified a CipherSpec that requires an alternative SSL provider."); /* 3325 */
#endif /* MQRCCF_SSL_ALT_PROVIDER_REQD */
#ifdef MQRCCF_OBJECT_ALREADY_EXISTS
ADD_MQ_REASON_TXT(MQRCCF_OBJECT_ALREADY_EXISTS, "Object already exists."); /* 4001 */
#endif /* MQRCCF_OBJECT_ALREADY_EXISTS */
#ifdef MQRCCF_OBJECT_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRCCF_OBJECT_WRONG_TYPE, "Object has wrong type."); /* 4002 */
#endif /* MQRCCF_OBJECT_WRONG_TYPE */
#ifdef MQRCCF_LIKE_OBJECT_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRCCF_LIKE_OBJECT_WRONG_TYPE, "New and existing objects have different type."); /* 4003 */
#endif /* MQRCCF_LIKE_OBJECT_WRONG_TYPE */
#ifdef MQRCCF_OBJECT_OPEN
ADD_MQ_REASON_TXT(MQRCCF_OBJECT_OPEN, "Object is open."); /* 4004 */
#endif /* MQRCCF_OBJECT_OPEN */
#ifdef MQRCCF_ATTR_VALUE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_ATTR_VALUE_ERROR, "Attribute value not valid."); /* 4005 */
#endif /* MQRCCF_ATTR_VALUE_ERROR */
#ifdef MQRCCF_UNKNOWN_Q_MGR
ADD_MQ_REASON_TXT(MQRCCF_UNKNOWN_Q_MGR, "Queue manager not known."); /* 4006 */
#endif /* MQRCCF_UNKNOWN_Q_MGR */
#ifdef MQRCCF_Q_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRCCF_Q_WRONG_TYPE, "Action not valid for the queue of specified type."); /* 4007 */
#endif /* MQRCCF_Q_WRONG_TYPE */
#ifdef MQRCCF_OBJECT_NAME_ERROR
ADD_MQ_REASON_TXT(MQRCCF_OBJECT_NAME_ERROR, "Object name not valid."); /* 4008 */
#endif /* MQRCCF_OBJECT_NAME_ERROR */
#ifdef MQRCCF_ALLOCATE_FAILED
ADD_MQ_REASON_TXT(MQRCCF_ALLOCATE_FAILED, "Allocation failed."); /* 4009 */
#endif /* MQRCCF_ALLOCATE_FAILED */
#ifdef MQRCCF_HOST_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRCCF_HOST_NOT_AVAILABLE, "Remote system not available."); /* 4010 */
#endif /* MQRCCF_HOST_NOT_AVAILABLE */
#ifdef MQRCCF_CONFIGURATION_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CONFIGURATION_ERROR, "Configuration error."); /* 4011 */
#endif /* MQRCCF_CONFIGURATION_ERROR */
#ifdef MQRCCF_CONNECTION_REFUSED
ADD_MQ_REASON_TXT(MQRCCF_CONNECTION_REFUSED, "Connection refused."); /* 4012 */
#endif /* MQRCCF_CONNECTION_REFUSED */
#ifdef MQRCCF_ENTRY_ERROR
ADD_MQ_REASON_TXT(MQRCCF_ENTRY_ERROR, "Invalid connection name."); /* 4013 */
#endif /* MQRCCF_ENTRY_ERROR */
#ifdef MQRCCF_SEND_FAILED
ADD_MQ_REASON_TXT(MQRCCF_SEND_FAILED, "Send failed."); /* 4014 */
#endif /* MQRCCF_SEND_FAILED */
#ifdef MQRCCF_RECEIVED_DATA_ERROR
ADD_MQ_REASON_TXT(MQRCCF_RECEIVED_DATA_ERROR, "Received data error."); /* 4015 */
#endif /* MQRCCF_RECEIVED_DATA_ERROR */
#ifdef MQRCCF_RECEIVE_FAILED
ADD_MQ_REASON_TXT(MQRCCF_RECEIVE_FAILED, "Receive failed."); /* 4016 */
#endif /* MQRCCF_RECEIVE_FAILED */
#ifdef MQRCCF_CONNECTION_CLOSED
ADD_MQ_REASON_TXT(MQRCCF_CONNECTION_CLOSED, "Connection closed."); /* 4017 */
#endif /* MQRCCF_CONNECTION_CLOSED */
#ifdef MQRCCF_NO_STORAGE
ADD_MQ_REASON_TXT(MQRCCF_NO_STORAGE, "Not enough storage available."); /* 4018 */
#endif /* MQRCCF_NO_STORAGE */
#ifdef MQRCCF_NO_COMMS_MANAGER
ADD_MQ_REASON_TXT(MQRCCF_NO_COMMS_MANAGER, "Communications manager not available."); /* 4019 */
#endif /* MQRCCF_NO_COMMS_MANAGER */
#ifdef MQRCCF_LISTENER_NOT_STARTED
ADD_MQ_REASON_TXT(MQRCCF_LISTENER_NOT_STARTED, "Listener not started."); /* 4020 */
#endif /* MQRCCF_LISTENER_NOT_STARTED */
#ifdef MQRCCF_BIND_FAILED
ADD_MQ_REASON_TXT(MQRCCF_BIND_FAILED, "Bind failed."); /* 4024 */
#endif /* MQRCCF_BIND_FAILED */
#ifdef MQRCCF_CHANNEL_INDOUBT
ADD_MQ_REASON_TXT(MQRCCF_CHANNEL_INDOUBT, "Channel in-doubt."); /* 4025 */
#endif /* MQRCCF_CHANNEL_INDOUBT */
#ifdef MQRCCF_MQCONN_FAILED
ADD_MQ_REASON_TXT(MQRCCF_MQCONN_FAILED, "MQCONN call failed."); /* 4026 */
#endif /* MQRCCF_MQCONN_FAILED */
#ifdef MQRCCF_MQOPEN_FAILED
ADD_MQ_REASON_TXT(MQRCCF_MQOPEN_FAILED, "MQOPEN call failed."); /* 4027 */
#endif /* MQRCCF_MQOPEN_FAILED */
#ifdef MQRCCF_MQGET_FAILED
ADD_MQ_REASON_TXT(MQRCCF_MQGET_FAILED, "MQGET call failed."); /* 4028 */
#endif /* MQRCCF_MQGET_FAILED */
#ifdef MQRCCF_MQPUT_FAILED
ADD_MQ_REASON_TXT(MQRCCF_MQPUT_FAILED, "MQPUT call failed."); /* 4029 */
#endif /* MQRCCF_MQPUT_FAILED */
#ifdef MQRCCF_PING_ERROR
ADD_MQ_REASON_TXT(MQRCCF_PING_ERROR, "Ping error."); /* 4030 */
#endif /* MQRCCF_PING_ERROR */
#ifdef MQRCCF_CHANNEL_IN_USE
ADD_MQ_REASON_TXT(MQRCCF_CHANNEL_IN_USE, "Channel in use."); /* 4031 */
#endif /* MQRCCF_CHANNEL_IN_USE */
#ifdef MQRCCF_CHANNEL_NOT_FOUND
ADD_MQ_REASON_TXT(MQRCCF_CHANNEL_NOT_FOUND, "Channel not found."); /* 4032 */
#endif /* MQRCCF_CHANNEL_NOT_FOUND */
#ifdef MQRCCF_UNKNOWN_REMOTE_CHANNEL
ADD_MQ_REASON_TXT(MQRCCF_UNKNOWN_REMOTE_CHANNEL, "Remote channel not known."); /* 4033 */
#endif /* MQRCCF_UNKNOWN_REMOTE_CHANNEL */
#ifdef MQRCCF_REMOTE_QM_UNAVAILABLE
ADD_MQ_REASON_TXT(MQRCCF_REMOTE_QM_UNAVAILABLE, "Remote queue manager not available."); /* 4034 */
#endif /* MQRCCF_REMOTE_QM_UNAVAILABLE */
#ifdef MQRCCF_REMOTE_QM_TERMINATING
ADD_MQ_REASON_TXT(MQRCCF_REMOTE_QM_TERMINATING, "Remote queue manager terminating."); /* 4035 */
#endif /* MQRCCF_REMOTE_QM_TERMINATING */
#ifdef MQRCCF_MQINQ_FAILED
ADD_MQ_REASON_TXT(MQRCCF_MQINQ_FAILED, "MQINQ call failed."); /* 4036 */
#endif /* MQRCCF_MQINQ_FAILED */
#ifdef MQRCCF_NOT_XMIT_Q
ADD_MQ_REASON_TXT(MQRCCF_NOT_XMIT_Q, "Queue is not a transmission queue."); /* 4037 */
#endif /* MQRCCF_NOT_XMIT_Q */
#ifdef MQRCCF_CHANNEL_DISABLED
ADD_MQ_REASON_TXT(MQRCCF_CHANNEL_DISABLED, "Channel disabled."); /* 4038 */
#endif /* MQRCCF_CHANNEL_DISABLED */
#ifdef MQRCCF_USER_EXIT_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRCCF_USER_EXIT_NOT_AVAILABLE, "User exit not available."); /* 4039 */
#endif /* MQRCCF_USER_EXIT_NOT_AVAILABLE */
#ifdef MQRCCF_COMMIT_FAILED
ADD_MQ_REASON_TXT(MQRCCF_COMMIT_FAILED, "Commit failed."); /* 4040 */
#endif /* MQRCCF_COMMIT_FAILED */
#ifdef MQRCCF_WRONG_CHANNEL_TYPE
ADD_MQ_REASON_TXT(MQRCCF_WRONG_CHANNEL_TYPE, "Parameter not allowed for this channel type."); /* 4041 */
#endif /* MQRCCF_WRONG_CHANNEL_TYPE */
#ifdef MQRCCF_CHANNEL_ALREADY_EXISTS
ADD_MQ_REASON_TXT(MQRCCF_CHANNEL_ALREADY_EXISTS, "Channel already exists."); /* 4042 */
#endif /* MQRCCF_CHANNEL_ALREADY_EXISTS */
#ifdef MQRCCF_DATA_TOO_LARGE
ADD_MQ_REASON_TXT(MQRCCF_DATA_TOO_LARGE, "Data too large."); /* 4043 */
#endif /* MQRCCF_DATA_TOO_LARGE */
#ifdef MQRCCF_CHANNEL_NAME_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CHANNEL_NAME_ERROR, "Channel name error."); /* 4044 */
#endif /* MQRCCF_CHANNEL_NAME_ERROR */
#ifdef MQRCCF_XMIT_Q_NAME_ERROR
ADD_MQ_REASON_TXT(MQRCCF_XMIT_Q_NAME_ERROR, "Transmission queue name error."); /* 4045 */
#endif /* MQRCCF_XMIT_Q_NAME_ERROR */
#ifdef MQRCCF_MCA_NAME_ERROR
ADD_MQ_REASON_TXT(MQRCCF_MCA_NAME_ERROR, "Message channel agent name error."); /* 4047 */
#endif /* MQRCCF_MCA_NAME_ERROR */
#ifdef MQRCCF_SEND_EXIT_NAME_ERROR
ADD_MQ_REASON_TXT(MQRCCF_SEND_EXIT_NAME_ERROR, "Channel send exit name error."); /* 4048 */
#endif /* MQRCCF_SEND_EXIT_NAME_ERROR */
#ifdef MQRCCF_SEC_EXIT_NAME_ERROR
ADD_MQ_REASON_TXT(MQRCCF_SEC_EXIT_NAME_ERROR, "Channel security exit name error."); /* 4049 */
#endif /* MQRCCF_SEC_EXIT_NAME_ERROR */
#ifdef MQRCCF_MSG_EXIT_NAME_ERROR
ADD_MQ_REASON_TXT(MQRCCF_MSG_EXIT_NAME_ERROR, "Channel message exit name error."); /* 4050 */
#endif /* MQRCCF_MSG_EXIT_NAME_ERROR */
#ifdef MQRCCF_RCV_EXIT_NAME_ERROR
ADD_MQ_REASON_TXT(MQRCCF_RCV_EXIT_NAME_ERROR, "Channel receive exit name error."); /* 4051 */
#endif /* MQRCCF_RCV_EXIT_NAME_ERROR */
#ifdef MQRCCF_XMIT_Q_NAME_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRCCF_XMIT_Q_NAME_WRONG_TYPE, "Transmission queue name not allowed for this channel type."); /* 4052 */
#endif /* MQRCCF_XMIT_Q_NAME_WRONG_TYPE */
#ifdef MQRCCF_MCA_NAME_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRCCF_MCA_NAME_WRONG_TYPE, "Message channel agent name not allowed for this channel type."); /* 4053 */
#endif /* MQRCCF_MCA_NAME_WRONG_TYPE */
#ifdef MQRCCF_DISC_INT_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRCCF_DISC_INT_WRONG_TYPE, "Disconnection interval not allowed for this channel type."); /* 4054 */
#endif /* MQRCCF_DISC_INT_WRONG_TYPE */
#ifdef MQRCCF_SHORT_RETRY_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRCCF_SHORT_RETRY_WRONG_TYPE, "Short retry parameter not allowed for this channel type."); /* 4055 */
#endif /* MQRCCF_SHORT_RETRY_WRONG_TYPE */
#ifdef MQRCCF_SHORT_TIMER_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRCCF_SHORT_TIMER_WRONG_TYPE, "Short timer parameter not allowed for this channel type."); /* 4056 */
#endif /* MQRCCF_SHORT_TIMER_WRONG_TYPE */
#ifdef MQRCCF_LONG_RETRY_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRCCF_LONG_RETRY_WRONG_TYPE, "Long retry parameter not allowed for this channel type."); /* 4057 */
#endif /* MQRCCF_LONG_RETRY_WRONG_TYPE */
#ifdef MQRCCF_LONG_TIMER_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRCCF_LONG_TIMER_WRONG_TYPE, "Long timer parameter not allowed for this channel type."); /* 4058 */
#endif /* MQRCCF_LONG_TIMER_WRONG_TYPE */
#ifdef MQRCCF_PUT_AUTH_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRCCF_PUT_AUTH_WRONG_TYPE, "Put authority parameter not allowed for this channel type."); /* 4059 */
#endif /* MQRCCF_PUT_AUTH_WRONG_TYPE */
#ifdef MQRCCF_MISSING_CONN_NAME
ADD_MQ_REASON_TXT(MQRCCF_MISSING_CONN_NAME, "Connection name parameter required but missing."); /* 4061 */
#endif /* MQRCCF_MISSING_CONN_NAME */
#ifdef MQRCCF_CONN_NAME_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CONN_NAME_ERROR, "Error in connection name parameter."); /* 4062 */
#endif /* MQRCCF_CONN_NAME_ERROR */
#ifdef MQRCCF_MQSET_FAILED
ADD_MQ_REASON_TXT(MQRCCF_MQSET_FAILED, "MQSET call failed."); /* 4063 */
#endif /* MQRCCF_MQSET_FAILED */
#ifdef MQRCCF_CHANNEL_NOT_ACTIVE
ADD_MQ_REASON_TXT(MQRCCF_CHANNEL_NOT_ACTIVE, "Channel not active."); /* 4064 */
#endif /* MQRCCF_CHANNEL_NOT_ACTIVE */
#ifdef MQRCCF_TERMINATED_BY_SEC_EXIT
ADD_MQ_REASON_TXT(MQRCCF_TERMINATED_BY_SEC_EXIT, "Channel terminated by security exit."); /* 4065 */
#endif /* MQRCCF_TERMINATED_BY_SEC_EXIT */
#ifdef MQRCCF_DYNAMIC_Q_SCOPE_ERROR
ADD_MQ_REASON_TXT(MQRCCF_DYNAMIC_Q_SCOPE_ERROR, "Dynamic queue scope error."); /* 4067 */
#endif /* MQRCCF_DYNAMIC_Q_SCOPE_ERROR */
#ifdef MQRCCF_CELL_DIR_NOT_AVAILABLE
ADD_MQ_REASON_TXT(MQRCCF_CELL_DIR_NOT_AVAILABLE, "Cell directory is not available."); /* 4068 */
#endif /* MQRCCF_CELL_DIR_NOT_AVAILABLE */
#ifdef MQRCCF_MR_COUNT_ERROR
ADD_MQ_REASON_TXT(MQRCCF_MR_COUNT_ERROR, "Message retry count not valid."); /* 4069 */
#endif /* MQRCCF_MR_COUNT_ERROR */
#ifdef MQRCCF_MR_COUNT_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRCCF_MR_COUNT_WRONG_TYPE, "Message-retry count parameter not allowed for this channel type."); /* 4070 */
#endif /* MQRCCF_MR_COUNT_WRONG_TYPE */
#ifdef MQRCCF_MR_EXIT_NAME_ERROR
ADD_MQ_REASON_TXT(MQRCCF_MR_EXIT_NAME_ERROR, "Channel message-retry exit name error."); /* 4071 */
#endif /* MQRCCF_MR_EXIT_NAME_ERROR */
#ifdef MQRCCF_MR_EXIT_NAME_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRCCF_MR_EXIT_NAME_WRONG_TYPE, "Message-retry exit parameter not allowed for this channel type."); /* 4072 */
#endif /* MQRCCF_MR_EXIT_NAME_WRONG_TYPE */
#ifdef MQRCCF_MR_INTERVAL_ERROR
ADD_MQ_REASON_TXT(MQRCCF_MR_INTERVAL_ERROR, "Message retry interval not valid."); /* 4073 */
#endif /* MQRCCF_MR_INTERVAL_ERROR */
#ifdef MQRCCF_MR_INTERVAL_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRCCF_MR_INTERVAL_WRONG_TYPE, "Message-retry interval parameter not allowed for this channel type."); /* 4074 */
#endif /* MQRCCF_MR_INTERVAL_WRONG_TYPE */
#ifdef MQRCCF_NPM_SPEED_ERROR
ADD_MQ_REASON_TXT(MQRCCF_NPM_SPEED_ERROR, "Nonpersistent message speed not valid."); /* 4075 */
#endif /* MQRCCF_NPM_SPEED_ERROR */
#ifdef MQRCCF_NPM_SPEED_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRCCF_NPM_SPEED_WRONG_TYPE, "Nonpersistent message speed parameter not allowed for this channel type."); /* 4076 */
#endif /* MQRCCF_NPM_SPEED_WRONG_TYPE */
#ifdef MQRCCF_HB_INTERVAL_ERROR
ADD_MQ_REASON_TXT(MQRCCF_HB_INTERVAL_ERROR, "Heartbeat interval not valid."); /* 4077 */
#endif /* MQRCCF_HB_INTERVAL_ERROR */
#ifdef MQRCCF_HB_INTERVAL_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRCCF_HB_INTERVAL_WRONG_TYPE, "Heartbeat interval parameter not allowed for this channel type."); /* 4078 */
#endif /* MQRCCF_HB_INTERVAL_WRONG_TYPE */
#ifdef MQRCCF_CHAD_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CHAD_ERROR, "Channel automatic definition error."); /* 4079 */
#endif /* MQRCCF_CHAD_ERROR */
#ifdef MQRCCF_CHAD_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRCCF_CHAD_WRONG_TYPE, "Channel automatic definition parameter not allowed for this channel type."); /* 4080 */
#endif /* MQRCCF_CHAD_WRONG_TYPE */
#ifdef MQRCCF_CHAD_EVENT_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CHAD_EVENT_ERROR, "Channel automatic definition event error."); /* 4081 */
#endif /* MQRCCF_CHAD_EVENT_ERROR */
#ifdef MQRCCF_CHAD_EVENT_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRCCF_CHAD_EVENT_WRONG_TYPE, "Channel automatic definition event parameter not allowed for this channel type."); /* 4082 */
#endif /* MQRCCF_CHAD_EVENT_WRONG_TYPE */
#ifdef MQRCCF_CHAD_EXIT_ERROR
ADD_MQ_REASON_TXT(MQRCCF_CHAD_EXIT_ERROR, "Channel automatic definition exit name error."); /* 4083 */
#endif /* MQRCCF_CHAD_EXIT_ERROR */
#ifdef MQRCCF_CHAD_EXIT_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRCCF_CHAD_EXIT_WRONG_TYPE, "Channel automatic definition exit parameter not allowed for this channel type."); /* 4084 */
#endif /* MQRCCF_CHAD_EXIT_WRONG_TYPE */
#ifdef MQRCCF_SUPPRESSED_BY_EXIT
ADD_MQ_REASON_TXT(MQRCCF_SUPPRESSED_BY_EXIT, "Action suppressed by exit program."); /* 4085 */
#endif /* MQRCCF_SUPPRESSED_BY_EXIT */
#ifdef MQRCCF_BATCH_INT_ERROR
ADD_MQ_REASON_TXT(MQRCCF_BATCH_INT_ERROR, "Batch interval not valid."); /* 4086 */
#endif /* MQRCCF_BATCH_INT_ERROR */
#ifdef MQRCCF_BATCH_INT_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRCCF_BATCH_INT_WRONG_TYPE, "Batch interval parameter not allowed for this channel type."); /* 4087 */
#endif /* MQRCCF_BATCH_INT_WRONG_TYPE */
#ifdef MQRCCF_NET_PRIORITY_ERROR
ADD_MQ_REASON_TXT(MQRCCF_NET_PRIORITY_ERROR, "Network priority value is not valid."); /* 4088 */
#endif /* MQRCCF_NET_PRIORITY_ERROR */
#ifdef MQRCCF_NET_PRIORITY_WRONG_TYPE
ADD_MQ_REASON_TXT(MQRCCF_NET_PRIORITY_WRONG_TYPE, "Network priority parameter not allowed for this channel type."); /* 4089 */
#endif /* MQRCCF_NET_PRIORITY_WRONG_TYPE */
#ifdef MQRCCF_CHANNEL_CLOSED
ADD_MQ_REASON_TXT(MQRCCF_CHANNEL_CLOSED, "Channel closed."); /* 4090 */
#endif /* MQRCCF_CHANNEL_CLOSED */
#ifdef MQRCCF_SSL_CIPHER_SPEC_ERROR
ADD_MQ_REASON_TXT(MQRCCF_SSL_CIPHER_SPEC_ERROR, "SSL cipher specification not valid."); /* 4092 */
#endif /* MQRCCF_SSL_CIPHER_SPEC_ERROR */
#ifdef MQRCCF_SSL_PEER_NAME_ERROR
ADD_MQ_REASON_TXT(MQRCCF_SSL_PEER_NAME_ERROR, "SSL peer name not valid."); /* 4093 */
#endif /* MQRCCF_SSL_PEER_NAME_ERROR */
#ifdef MQRCCF_SSL_CLIENT_AUTH_ERROR
ADD_MQ_REASON_TXT(MQRCCF_SSL_CLIENT_AUTH_ERROR, "SSL client authentication not valid."); /* 4094 */
#endif /* MQRCCF_SSL_CLIENT_AUTH_ERROR */
#ifdef MQRCCF_RETAINED_NOT_SUPPORTED
ADD_MQ_REASON_TXT(MQRCCF_RETAINED_NOT_SUPPORTED, "Retained messages used on restricted stream."); /* 4095 */
#endif /* MQRCCF_RETAINED_NOT_SUPPORTED */
#ifdef MQRC_REOPEN_EXCL_INPUT_ERROR
ADD_MQ_REASON_TXT(MQRC_REOPEN_EXCL_INPUT_ERROR, "An open object does not have the correct ImqObject open options and requires one or more additional options."); /* 6100 */
#endif /* MQRC_REOPEN_EXCL_INPUT_ERROR */
#ifdef MQRC_REOPEN_INQUIRE_ERROR
ADD_MQ_REASON_TXT(MQRC_REOPEN_INQUIRE_ERROR, "An open object does not have the correct ImqObject open options and requires one or more additional options."); /* 6101 */
#endif /* MQRC_REOPEN_INQUIRE_ERROR */
#ifdef MQRC_REOPEN_SAVED_CONTEXT_ERR
ADD_MQ_REASON_TXT(MQRC_REOPEN_SAVED_CONTEXT_ERR, "An open object does not have the correct ImqObject open options and requires one or more additional options."); /* 6102 */
#endif /* MQRC_REOPEN_SAVED_CONTEXT_ERR */
#ifdef MQRC_REOPEN_TEMPORARY_Q_ERROR
ADD_MQ_REASON_TXT(MQRC_REOPEN_TEMPORARY_Q_ERROR, "An open object does not have the correct ImqObject open options and requires one or more additional options."); /* 6103 */
#endif /* MQRC_REOPEN_TEMPORARY_Q_ERROR */
#ifdef MQRC_ATTRIBUTE_LOCKED
ADD_MQ_REASON_TXT(MQRC_ATTRIBUTE_LOCKED, "An attempt has been made to change the value of an attribute of an object while that object is open, or, for an ImqQueueManager object, while that object is connected."); /* 6104 */
#endif /* MQRC_ATTRIBUTE_LOCKED */
#ifdef MQRC_CURSOR_NOT_VALID
ADD_MQ_REASON_TXT(MQRC_CURSOR_NOT_VALID, "The browse cursor for an open queue has been invalidated since it was last used by an implicit reopen."); /* 6105 */
#endif /* MQRC_CURSOR_NOT_VALID */
#ifdef MQRC_ENCODING_ERROR
ADD_MQ_REASON_TXT(MQRC_ENCODING_ERROR, "The encoding of the (next) message item needs to be MQENC_NATIVE for pasting."); /* 6106 */
#endif /* MQRC_ENCODING_ERROR */
#ifdef MQRC_STRUC_ID_ERROR
ADD_MQ_REASON_TXT(MQRC_STRUC_ID_ERROR, "The structure id for the (next) message item, which is derived from the 4 characters beginning at the data pointer, is either missing or is inconsistent with the class of object into which the item is being pasted."); /* 6107 */
#endif /* MQRC_STRUC_ID_ERROR */
#ifdef MQRC_NULL_POINTER
ADD_MQ_REASON_TXT(MQRC_NULL_POINTER, "A null pointer has been supplied where a nonnull pointer is either required or implied."); /* 6108 */
#endif /* MQRC_NULL_POINTER */
#ifdef MQRC_NO_CONNECTION_REFERENCE
ADD_MQ_REASON_TXT(MQRC_NO_CONNECTION_REFERENCE, "The connection reference is null."); /* 6109 */
#endif /* MQRC_NO_CONNECTION_REFERENCE */
#ifdef MQRC_NO_BUFFER
ADD_MQ_REASON_TXT(MQRC_NO_BUFFER, "No buffer is available."); /* 6110 */
#endif /* MQRC_NO_BUFFER */
#ifdef MQRC_BINARY_DATA_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRC_BINARY_DATA_LENGTH_ERROR, "The length of the binary data is inconsistent with the length of the target attribute."); /* 6111 */
#endif /* MQRC_BINARY_DATA_LENGTH_ERROR */
#ifdef MQRC_BUFFER_NOT_AUTOMATIC
ADD_MQ_REASON_TXT(MQRC_BUFFER_NOT_AUTOMATIC, "A user-defined (and managed) buffer cannot be resized."); /* 6112 */
#endif /* MQRC_BUFFER_NOT_AUTOMATIC */
#ifdef MQRC_INSUFFICIENT_BUFFER
ADD_MQ_REASON_TXT(MQRC_INSUFFICIENT_BUFFER, "There is insufficient buffer space available after the data pointer to accommodate the request."); /* 6113 */
#endif /* MQRC_INSUFFICIENT_BUFFER */
#ifdef MQRC_INSUFFICIENT_DATA
ADD_MQ_REASON_TXT(MQRC_INSUFFICIENT_DATA, "There is insufficient data after the data pointer to accommodate the request."); /* 6114 */
#endif /* MQRC_INSUFFICIENT_DATA */
#ifdef MQRC_DATA_TRUNCATED
ADD_MQ_REASON_TXT(MQRC_DATA_TRUNCATED, "Data has been truncated when copying from one buffer to another."); /* 6115 */
#endif /* MQRC_DATA_TRUNCATED */
#ifdef MQRC_ZERO_LENGTH
ADD_MQ_REASON_TXT(MQRC_ZERO_LENGTH, "A zero length has been supplied where a positive length is either required or implied."); /* 6116 */
#endif /* MQRC_ZERO_LENGTH */
#ifdef MQRC_NEGATIVE_LENGTH
ADD_MQ_REASON_TXT(MQRC_NEGATIVE_LENGTH, "Length is negative."); /* 6117 */
#endif /* MQRC_NEGATIVE_LENGTH */
#ifdef MQRC_NEGATIVE_OFFSET
ADD_MQ_REASON_TXT(MQRC_NEGATIVE_OFFSET, "A negative offset has been supplied where a zero or positive offset is required."); /* 6118 */
#endif /* MQRC_NEGATIVE_OFFSET */
#ifdef MQRC_INCONSISTENT_FORMAT
ADD_MQ_REASON_TXT(MQRC_INCONSISTENT_FORMAT, "The format of the (next) message item is inconsistent with the class of object into which the item is being pasted."); /* 6119 */
#endif /* MQRC_INCONSISTENT_FORMAT */
#ifdef MQRC_INCONSISTENT_OBJECT_STATE
ADD_MQ_REASON_TXT(MQRC_INCONSISTENT_OBJECT_STATE, "There is an inconsistency between this object, which is open, and the referenced ImqQueueManager object, which is not connected."); /* 6120 */
#endif /* MQRC_INCONSISTENT_OBJECT_STATE */
#ifdef MQRC_CONTEXT_OBJECT_NOT_VALID
ADD_MQ_REASON_TXT(MQRC_CONTEXT_OBJECT_NOT_VALID, "The ImqPutMessageOptions context reference does not reference a valid ImqQueue object."); /* 6121 */
#endif /* MQRC_CONTEXT_OBJECT_NOT_VALID */
#ifdef MQRC_CONTEXT_OPEN_ERROR
ADD_MQ_REASON_TXT(MQRC_CONTEXT_OPEN_ERROR, "The ImqPutMessageOptions context reference references an ImqQueue object that could not be opened to establish a context."); /* 6122 */
#endif /* MQRC_CONTEXT_OPEN_ERROR */
#ifdef MQRC_STRUC_LENGTH_ERROR
ADD_MQ_REASON_TXT(MQRC_STRUC_LENGTH_ERROR, "The length of a data structure is inconsistent with its content."); /* 6123 */
#endif /* MQRC_STRUC_LENGTH_ERROR */
#ifdef MQRC_NOT_CONNECTED
ADD_MQ_REASON_TXT(MQRC_NOT_CONNECTED, "A method failed because a required connection to a queue manager was not available, and a connection cannot be established implicitly because the IMQ_IMPL_CONN flag of the ImqQueueManager behavior class attribute is FALSE."); /* 6124 */
#endif /* MQRC_NOT_CONNECTED */
#ifdef MQRC_NOT_OPEN
ADD_MQ_REASON_TXT(MQRC_NOT_OPEN, "A method failed because an object was not open, and opening cannot be accomplished implicitly because the IMQ_IMPL_OPEN flag of the ImqObject behavior class attribute is FALSE."); /* 6125 */
#endif /* MQRC_NOT_OPEN */
#ifdef MQRC_DISTRIBUTION_LIST_EMPTY
ADD_MQ_REASON_TXT(MQRC_DISTRIBUTION_LIST_EMPTY, "An ImqDistributionList failed to open because there are no ImqQueue objects referenced."); /* 6126 */
#endif /* MQRC_DISTRIBUTION_LIST_EMPTY */
#ifdef MQRC_INCONSISTENT_OPEN_OPTIONS
ADD_MQ_REASON_TXT(MQRC_INCONSISTENT_OPEN_OPTIONS, "A method failed because the object is open, and the ImqObject open options are inconsistent with the required operation."); /* 6127 */
#endif /* MQRC_INCONSISTENT_OPEN_OPTIONS */
#ifdef MQRC_WRONG_VERSION
ADD_MQ_REASON_TXT(MQRC_WRONG_VERSION, "A method failed because a version number specified or encountered is either incorrect or not supported."); /* 6128 */
#endif /* MQRC_WRONG_VERSION */
#ifdef MQRC_REFERENCE_ERROR
ADD_MQ_REASON_TXT(MQRC_REFERENCE_ERROR, "An object reference is invalid."); /* 6129 */
#endif /* MQRC_REFERENCE_ERROR */
