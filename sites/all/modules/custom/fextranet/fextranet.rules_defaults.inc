<?php
/**
 * Created by PhpStorm.
 * User: mositis
 * Date: 1/25/2016
 * Time: 1:59 PM
 */
function fextranet_default_rules_configuration() {
  $configs = array();

  // Send email alerts to user and admin
  $rule = '{ "rules_extranet_membership_request_submitted_send_emails_" : {
    "LABEL" : "Extranet: Membership request: submitted.  Send emails.",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "REQUIRES" : [ "rules", "mimemail", "php", "group" ],
    "ON" : { "group_membership_insert" : [] },
    "IF" : [
      { "entity_is_of_type" : { "entity" : [ "group-membership" ], "type" : "group_membership" } },
      { "data_is" : { "data" : [ "group-membership:status" ], "value" : "requested" } },
      { "NOT data_is_empty" : { "data" : [ "site:current-user:mail" ] } }
    ],
    "DO" : [
      { "drupal_message" : { "message" : "Thank you for requesting access to Sales Insider! Your request has been sent for approval." } },
      { "mimemail" : {
          "key" : "extranet_membership_request",
          "to" : "[site:current-user:mail]",
          "from_name" : "Sales Insider",
          "from_mail" : "salesinsider@flukenetworks.com",
          "subject" : "Your request for access to Sales Insider has been received!",
          "body" : "We have received your request and will respond as soon as possible. You will get an email as soon as we review your request.",
          "plaintext" : "We have received your request and will respond as soon as possible. You will get an email as soon as we review your request.",
          "language" : [ "" ]
        }
      },
      { "mimemail" : {
          "key" : "extranet_membership_request_admin",
          "to" : "\u003C?php\r\nreturn _fex_gm_to_email($group_membership);\r\n?\u003E",
          "from_name" : "Sales Insider",
          "from_mail" : "salesinsider@flukenetworks.com",
          "subject" : "New Request for Sales Insider Access",
          "body" : "User [group-membership:user] has requested access to Sales Insider on [group-membership:requested-on]. Please review this request and take action to approve or deny. To do so, please \u003Ca href=\u0022[site:url]\/group\/[group-membership:group:gid]\/member\u0022\u003Elog in to the Fluke Networks website\u003C\/a\u003E.\r\n\r\nName: [site:current-user:field-user-first-name] [site:current-user:field-user-last-name]\r\nE-mail: [site:current-user:mail]\r\nCompany: [site:current-user:field-user-country]\r\nCountry: [site:current-user:field-user-country]\r\nThanks!\r\n\r\n- The Fluke Networks Website",
          "plaintext" : "User [group-membership:user] has requested access to Sales Insider on [group-membership:requested-on]. Since you\u0027re responsible for approving these requests, please take a moment and review to see if they should get access. To do so, please log in the the Fluke Networks website using the following URL.\r\n\r\n[site:url]\/group\/[group-membership:group:gid]\/member\r\n\r\nThanks!\r\n\r\n- The Fluke Networks Website",
          "language" : [ "" ]
        }
      }
    ]
  }
}';
  $configs['rules_extranet_membership_request_submitted_send_emails_'] = rules_import($rule);

  // Send approved email to User.
  $rule = '{ "rules_extranet_membership_request_approved_send_email_to_user" : {
    "LABEL" : "Extranet: Membership request: approved..  Send email to user",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "REQUIRES" : [ "rules", "rules_i18n", "mimemail", "group" ],
    "ON" : { "group_membership_update" : [] },
    "IF" : [
      { "entity_is_of_type" : { "entity" : [ "group-membership" ], "type" : "group_membership" } },
      { "data_is" : { "data" : [ "group-membership:status" ], "value" : "active" } },
      { "NOT data_is_empty" : { "data" : [ "site:current-user:mail" ] } }
    ],
    "DO" : [
      { "user_add_role" : {
          "account" : [ "group-membership:user" ],
          "roles" : { "value" : { "22" : "22" } }
        }
      },
      { "mimemail" : {
          "USING" : {
            "key" : "extranet_membership_approval",
            "to" : [ "group-membership:user:mail" ],
            "cc" : [ "" ],
            "from_name" : "Sales Insider",
            "from_mail" : "sales-insider@flukenetworks.com",
            "subject" : "Sales Insider access granted!",
            "body" : "\u003Cp\u003EYour request for access to the Fluke Networks Sales Insider has been approved!\u003C\/p\u003E\r\n\u003Cp\u003EIf you are an Authorized Channel Partner in Europe, Middle East \u0026 Africa, Sales Insider also comes with an additional service called Opportunity Insider. You will find a link to it in the top navigation bar of your Sales Insider. The same password you use for Sales Insider will also give you access to Opportunity Insider. Opportunity Insider access will be granted automatically to everyone who gets Sales Insider access.\u003C\/p\u003E\r\n\u003Cp\u003EIn the Americas and Asia Pacific, please request Opportunity Insider access separately from your Regional Sales Manager.\u003C\/p\u003E\r\n\u003Cp\u003EOpportunity Insider is the Extranet Site which allows partners to log into the Fluke Networks CRM through a secure website. Through this Portal, Partners can access Fluke Networks Customer data for the purpose of Deal Registration and Opportunity creation.\u003C\/p\u003E\r\n\u003Cp\u003EFor more information and training, please visit the \u003Ca href=\u0022[site:url]\/extranet\u0022\u003EFluke Networks website\u003C\/a\u003E\u003C\/p\u003E\r\n\u003Cp\u003ENeed additional training? If so, talk to your Fluke Networks Regional Sales Manager about Opportunity Insider.\u003C\/p\u003E\r\n\u003Cp\u003ESales Insider\u003C\/p\u003E",
            "plaintext" : "Your request for access to the Fluke Networks Sales Insider has been approved!\r\n\r\n[site:url]\/extranet",
            "language" : [ "" ]
          },
          "PROVIDE" : { "send_status" : { "send_status" : "Send status" } }
        }
      }
    ]
  }
}';

  $configs['rules_extranet_membership_request_approved_send_email_to_user'] = rules_import($rule);

  // Send Denial email to User.
  /* THIS RULE JUST SUCKS. REDO THIS BASTARD MANUALLY */
  /*
  $rule ='{ "rules_extranet_membership_request_denied_removed_send_email_to_u" : {
    "LABEL" : "Extranet: Membership request: denied\/removed..  Send email to user ",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "REQUIRES" : [ "rules", "group" ],
    "ON" : { "group_membership_update" : [] },
    "IF" : [
      { "entity_is_of_type" : { "entity" : [ "group-membership" ], "type" : "group_membership" } },
      { "data_is" : { "data" : [ "group-membership:status" ], "value" : "blocked" } },
      { "NOT data_is_empty" : { "data" : [ "site:current-user:mail" ] } }
    ],
    "DO" : [
      { "mail" : {
          "to" : [ "group-membership:user:mail" ],
          "subject" : "Unable to grant access",
          "message" : "We apologize, but your request for access to Sales Inside has been denied.",
          "from" : "salesinsider@flukenetworks.com",
          "language" : [ "" ]
        }
      }
    ]
  }
}}';
  $configs['rules_extranet_membership_request_denied_removed_send_email_to_u'] = rules_import($rule); */

  $rule = '{ "fextranet_extranet_membership_manually_added" : {
    "LABEL" : "Extranet: Membership manually added",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "REQUIRES" : [ "rules", "group" ],
    "ON" : { "group_membership_insert" : [] },
    "IF" : [
      { "entity_is_of_type" : { "entity" : [ "group-membership" ], "type" : "group_membership" } },
      { "data_is" : { "data" : [ "group-membership:status" ], "value" : "active" } },
      { "NOT data_is_empty" : { "data" : [ "site:current-user:mail" ] } }
    ],
    "DO" : [
      { "drupal_message" : { "message" : "The user has been added to the [group-membership:group] group." } },
      { "user_add_role" : {
          "account" : [ "group-membership:user" ],
          "roles" : { "value" : { "22" : "22" } }
        }
      }
    ]
  }
}';
  $configs['fextranet_extranet_membership_manually_added'] = rules_import($rule);

  return $configs;
}