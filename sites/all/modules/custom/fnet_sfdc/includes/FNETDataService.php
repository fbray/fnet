<?php

class sfdc_AllowFieldTruncationHeader {
  public $allowFieldTruncation;//boolean
}

class sfdc_CallOptions {
  public $client;//string
}

class sfdc_DebuggingHeader {
  public $categories;//LogInfo
  public $debugLevel;//LogType
}

class sfdc_LogInfo {
  public $category;//LogCategory
  public $level;//LogCategoryLevel
}

class sfdc_DebuggingInfo {
  public $debugLog;//string
}

class sfdc_SessionHeader {
  public $sessionId;//string
}

class sfdc_QueryResult {
  public $done;//boolean
  public $queryLocator;//string
  public $records;//sObject
  public $size;//int
}

class sfdc_sObject {
  public $fieldsToNull;//string
  public $Id;//ID
}

class sfdc_AMS_Product_Family__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//AMS_Product_Family__c
  public $ParentId;//ID
}

class sfdc_AMS_Product_Family__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Model_Group__c;//string
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $ProductFamilyID__c;//string
  public $ProductFamilyName__c;//string
  public $Products__r;//QueryResult
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_Account {
  public $AccountContactRoles;//QueryResult
  public $AccountContacts__r;//QueryResult
  public $AccountId__c;//string
  public $AccountNumber;//string
  public $AccountPartnersFrom;//QueryResult
  public $AccountPartnersTo;//QueryResult
  public $AccountSource;//string
  public $ActivityHistories;//QueryResult
  public $AnnualRevenue;//double
  public $Assets;//QueryResult
  public $Attachments;//QueryResult
  public $BillingCity;//string
  public $BillingCountry;//string
  public $BillingLatitude;//double
  public $BillingLongitude;//double
  public $BillingPostalCode;//string
  public $BillingState;//string
  public $BillingStreet;//string
  public $Cases;//QueryResult
  public $ChildAccounts;//QueryResult
  public $Contacts;//QueryResult
  public $Contracts;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Description;//string
  public $Email__c;//string
  public $Entitlements;//QueryResult
  public $Events;//QueryResult
  public $FNET_Key_Account__c;//boolean
  public $Fax;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Feeds;//QueryResult
  public $Gold_Number__c;//string
  public $Gold_PIN__c;//string
  public $Histories;//QueryResult
  public $Industry;//string
  public $IsDeleted;//boolean
  public $IsPartner;//boolean
  public $Jigsaw;//string
  public $JigsawCompanyId;//string
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $MasterRecord;//Account
  public $MasterRecordId;//ID
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $NumberOfEmployees;//int
  public $Onyx_Company_Record__c;//string
  public $OpenActivities;//QueryResult
  public $Opportunities;//QueryResult
  public $OpportunityOrders__r;//QueryResult
  public $OpportunityPartnersTo;//QueryResult
  public $OrderPartners__r;//QueryResult
  public $Orders;//QueryResult
  public $Owner;//User
  public $OwnerId;//ID
  public $Ownership;//string
  public $Parent;//Account
  public $ParentId;//ID
  public $PartnersFrom;//QueryResult
  public $PartnersTo;//QueryResult
  public $Phone;//string
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Rating;//string
  public $Reseller_Queue_ID__c;//string
  public $SDOC__SDoc_Relationships__r;//QueryResult
  public $Sales_Region_Info__c;//string
  public $Sales_Region__c;//ID
  public $Sales_Region__r;//Ref_Country_to_Sales_Region__c
  public $SalesforceCustomer;//string
  public $ServiceContracts;//QueryResult
  public $Shares;//QueryResult
  public $ShippingCity;//string
  public $ShippingCountry;//string
  public $ShippingLatitude;//double
  public $ShippingLongitude;//double
  public $ShippingPostalCode;//string
  public $ShippingState;//string
  public $ShippingStreet;//string
  public $Sic;//string
  public $SicDesc;//string
  public $Site;//string
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
  public $TickerSymbol;//string
  public $Type;//string
  public $Website;//string
  public $mkto_si__WebActivityCache__r;//QueryResult
  public $qbdialer__Dialer_Query_Items__r;//QueryResult
  public $qbdialer__Dials__c;//double
  public $qbdialer__LastCallTime__c;//dateTime
  public $qbdialer__ResponseTime__c;//double
  public $qbdialer__Seek_Initiative_Items__r;//QueryResult
}

class sfdc_AccountContactRole {
  public $Account;//Account
  public $AccountId;//ID
  public $Contact;//Contact
  public $ContactId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDeleted;//boolean
  public $IsPrimary;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Role;//string
  public $SystemModstamp;//dateTime
}

class sfdc_AccountContact__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//AccountContact__c
  public $ParentId;//ID
}

class sfdc_AccountContact__c {
  public $Account__c;//ID
  public $Account__r;//Account
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $Contact__c;//ID
  public $Contact__r;//Contact
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_AccountFeed {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//Account
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_AccountHistory {
  public $Account;//Account
  public $AccountId;//ID
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
}

class sfdc_AccountPartner {
  public $AccountFrom;//Account
  public $AccountFromId;//ID
  public $AccountTo;//Account
  public $AccountToId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDeleted;//boolean
  public $IsPrimary;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Opportunity;//Opportunity
  public $OpportunityId;//ID
  public $ReversePartnerId;//ID
  public $Role;//string
  public $SystemModstamp;//dateTime
}

class sfdc_AccountShare {
  public $Account;//Account
  public $AccountAccessLevel;//string
  public $AccountId;//ID
  public $CaseAccessLevel;//string
  public $ContactAccessLevel;//string
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $OpportunityAccessLevel;//string
  public $RowCause;//string
  public $UserOrGroupId;//ID
}

class sfdc_ActivityHistory {
  public $Account;//Account
  public $AccountId;//ID
  public $ActivityDate;//date
  public $ActivityId__c;//string
  public $ActivityType;//string
  public $Activity_Result__c;//string
  public $CallDisposition;//string
  public $CallDurationInSeconds;//int
  public $CallObject;//string
  public $CallType;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Delta_in_minutes__c;//double
  public $Description;//string
  public $DurationInMinutes;//int
  public $EVAL_Model__c;//string
  public $EVAL_Order_Status__c;//string
  public $EVAL_Purchase_Date__c;//date
  public $EVAL_Return_Date__c;//date
  public $EVAL_Serial_Number__c;//string
  public $EVAL_Ship_Date__c;//date
  public $EndDateTime;//dateTime
  public $IsAllDayEvent;//boolean
  public $IsClosed;//boolean
  public $IsDeleted;//boolean
  public $IsReminderSet;//boolean
  public $IsTask;//boolean
  public $IsVisibleInSelfService;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Location;//string
  public $Owner;//Name
  public $OwnerId;//ID
  public $Priority;//string
  public $ReminderDateTime;//dateTime
  public $Status;//string
  public $Subject;//string
  public $SystemModstamp;//dateTime
  public $What;//Name
  public $WhatId;//ID
  public $Who;//Name
  public $WhoId;//ID
  public $qbdialer__CallRecordingURL__c;//string
  public $qbdialer__Call_Date_Time__c;//dateTime
  public $qbdialer__Call_Dial_Number__c;//double
  public $qbdialer__Call_Hour__c;//string
  public $qbdialer__Call_Lead_Status__c;//string
  public $qbdialer__Call_Ring_Time__c;//double
  public $qbdialer__Call_Time_Zone__c;//string
  public $qbdialer__Callback_Date_Time__c;//dateTime
  public $qbdialer__ImpressionId__c;//double
  public $qbdialer__SMSReminder__c;//boolean
}

class sfdc_AdditionalNumber {
  public $CallCenterId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Phone;//string
  public $SystemModstamp;//dateTime
}

class sfdc_ApexClass {
  public $ApiVersion;//double
  public $Body;//string
  public $BodyCrc;//double
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsValid;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $LengthWithoutComments;//int
  public $Name;//string
  public $NamespacePrefix;//string
  public $SetupEntityAccessItems;//QueryResult
  public $Status;//string
  public $SystemModstamp;//dateTime
}

class sfdc_ApexComponent {
  public $ApiVersion;//double
  public $ControllerKey;//string
  public $ControllerType;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Markup;//string
  public $MasterLabel;//string
  public $Name;//string
  public $NamespacePrefix;//string
  public $SystemModstamp;//dateTime
}

class sfdc_ApexLog {
  public $Application;//string
  public $DurationMilliseconds;//int
  public $LastModifiedDate;//dateTime
  public $Location;//string
  public $LogLength;//int
  public $LogUser;//Name
  public $LogUserId;//ID
  public $Operation;//string
  public $Request;//string
  public $StartTime;//dateTime
  public $Status;//string
  public $SystemModstamp;//dateTime
}

class sfdc_ApexPage {
  public $ApiVersion;//double
  public $ControllerKey;//string
  public $ControllerType;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $IsAvailableInTouch;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Markup;//string
  public $MasterLabel;//string
  public $Name;//string
  public $NamespacePrefix;//string
  public $SetupEntityAccessItems;//QueryResult
  public $SystemModstamp;//dateTime
}

class sfdc_ApexTestQueueItem {
  public $ApexClass;//ApexClass
  public $ApexClassId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $ExtendedStatus;//string
  public $ParentJobId;//ID
  public $Status;//string
  public $SystemModstamp;//dateTime
}

class sfdc_ApexTestResult {
  public $ApexClass;//ApexClass
  public $ApexClassId;//ID
  public $ApexLog;//ApexLog
  public $ApexLogId;//ID
  public $AsyncApexJob;//AsyncApexJob
  public $AsyncApexJobId;//ID
  public $Message;//string
  public $MethodName;//string
  public $Outcome;//string
  public $QueueItem;//ApexTestQueueItem
  public $QueueItemId;//ID
  public $StackTrace;//string
  public $SystemModstamp;//dateTime
  public $TestTimestamp;//dateTime
}

class sfdc_ApexTrigger {
  public $ApiVersion;//double
  public $Body;//string
  public $BodyCrc;//double
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsValid;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $LengthWithoutComments;//int
  public $Name;//string
  public $NamespacePrefix;//string
  public $Status;//string
  public $SystemModstamp;//dateTime
  public $TableEnumOrId;//string
  public $UsageAfterDelete;//boolean
  public $UsageAfterInsert;//boolean
  public $UsageAfterUndelete;//boolean
  public $UsageAfterUpdate;//boolean
  public $UsageBeforeDelete;//boolean
  public $UsageBeforeInsert;//boolean
  public $UsageBeforeUpdate;//boolean
  public $UsageIsBulk;//boolean
}

class sfdc_Approval {
  public $ApproveComment;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Owner;//User
  public $OwnerId;//ID
  public $Parent;//Contract
  public $ParentId;//ID
  public $RequestComment;//string
  public $Status;//string
  public $SystemModstamp;//dateTime
}

class sfdc_Asset {
  public $AMS_ProductFamilyId__c;//string
  public $AMS_ProductFamilyName__c;//string
  public $Account;//Account
  public $AccountId;//ID
  public $ActivityHistories;//QueryResult
  public $AssetHistories__r;//QueryResult
  public $Assets__r;//QueryResult
  public $Attachments;//QueryResult
  public $Cases;//QueryResult
  public $Contact;//Contact
  public $ContactId;//ID
  public $ContractLineItems;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Description;//string
  public $Device_Users__r;//QueryResult
  public $Distributor_Contact__c;//ID
  public $Distributor_Contact__r;//Contact
  public $Entitlements;//QueryResult
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Feeds;//QueryResult
  public $Histories;//QueryResult
  public $InstallDate;//date
  public $IsCompetitorProduct;//boolean
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Main_Unit__c;//boolean
  public $Migrated_Distributor_Email__c;//string
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Onyx_Account_Id__c;//string
  public $Onyx_Asset_Id__c;//string
  public $Onyx_Contact_Id__c;//string
  public $Onyx_Product_Number__c;//string
  public $OpenActivities;//QueryResult
  public $Opportunity_Product__r;//QueryResult
  public $Order_Products__r;//QueryResult
  public $Parent_Asset__c;//ID
  public $Parent_Asset__r;//Asset
  public $Price;//double
  public $Primary_Key__c;//string
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Product2;//Product2
  public $Product2Id;//ID
  public $Product_Description__c;//string
  public $Product_Name__c;//string
  public $PurchaseDate;//date
  public $Purchase_Order__c;//string
  public $Quantity;//double
  public $Quote_Line_Items__r;//QueryResult
  public $Registration_Code__c;//string
  public $Registration_Source__c;//string
  public $SDOC__SDoc_Relationships__r;//QueryResult
  public $Sales_Order__c;//string
  public $SerialNumber;//string
  public $Serial_Numbers__c;//string
  public $Status;//string
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
  public $UsageEndDate;//date
  public $Web_Displayable__c;//boolean
  public $Web_Registered__c;//boolean
}

class sfdc_AssetCreationRule__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//AssetCreationRule__c
  public $ParentId;//ID
}

class sfdc_AssetCreationRule__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Product_Code__c;//string
  public $Product_Family__c;//string
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_AssetFeed {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//Asset
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_AssetHistory {
  public $Asset;//Asset
  public $AssetId;//ID
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
}

class sfdc_AssetHistory_Custom__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//AssetHistory_Custom__c
  public $ParentId;//ID
}

class sfdc_AssetHistory_Custom__c {
  public $ActivityHistories;//QueryResult
  public $Asset__c;//ID
  public $Asset__r;//Asset
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Date__c;//dateTime
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Field__c;//string
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $New_Value__c;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Old_Value__c;//string
  public $OpenActivities;//QueryResult
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
  public $User__c;//ID
  public $User__r;//User
}

class sfdc_AssignmentRule {
  public $Active;//boolean
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $SobjectType;//string
  public $SystemModstamp;//dateTime
}

class sfdc_AsyncApexJob {
  public $ApexClass;//ApexClass
  public $ApexClassId;//ID
  public $CompletedDate;//dateTime
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $ExtendedStatus;//string
  public $JobItemsProcessed;//int
  public $JobType;//string
  public $LastProcessed;//string
  public $LastProcessedOffset;//int
  public $MethodName;//string
  public $NumberOfErrors;//int
  public $ParentJobId;//ID
  public $Status;//string
  public $TotalJobItems;//int
}

class sfdc_Attachment {
  public $Body;//base64Binary
  public $BodyLength;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $IsDeleted;//boolean
  public $IsPrivate;//boolean
  public $LastModifiedBy;//Name
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Owner;//Name
  public $OwnerId;//ID
  public $Parent;//Name
  public $ParentId;//ID
  public $SystemModstamp;//dateTime
}

class sfdc_AuthProvider {
  public $AuthorizeUrl;//string
  public $ConsumerKey;//string
  public $ConsumerSecret;//string
  public $CreatedDate;//dateTime
  public $DefaultScopes;//string
  public $DeveloperName;//string
  public $ErrorUrl;//string
  public $ExecutionUserId;//ID
  public $FriendlyName;//string
  public $ProviderType;//string
  public $RegistrationHandlerId;//ID
  public $TokenUrl;//string
  public $UserInfoUrl;//string
}

class sfdc_BrandTemplate {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $DeveloperName;//string
  public $IsActive;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $NamespacePrefix;//string
  public $SystemModstamp;//dateTime
  public $Value;//string
}

class sfdc_BusinessHours {
  public $Cases;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Entitlements;//QueryResult
  public $FridayEndTime;//time
  public $FridayStartTime;//time
  public $IsActive;//boolean
  public $IsDefault;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $MondayEndTime;//time
  public $MondayStartTime;//time
  public $Name;//string
  public $SaturdayEndTime;//time
  public $SaturdayStartTime;//time
  public $SundayEndTime;//time
  public $SundayStartTime;//time
  public $SystemModstamp;//dateTime
  public $ThursdayEndTime;//time
  public $ThursdayStartTime;//time
  public $TimeZoneSidKey;//string
  public $TuesdayEndTime;//time
  public $TuesdayStartTime;//time
  public $WednesdayEndTime;//time
  public $WednesdayStartTime;//time
}

class sfdc_BusinessProcess {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $IsActive;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $NamespacePrefix;//string
  public $SystemModstamp;//dateTime
  public $TableEnumOrId;//string
}

class sfdc_CallCenter {
  public $AdapterUrl;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CustomSettings;//string
  public $InternalName;//string
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $SystemModstamp;//dateTime
  public $Version;//double
}

class sfdc_Campaign {
  public $ActivityHistories;//QueryResult
  public $ActualCost;//double
  public $AmountAllOpportunities;//double
  public $AmountWonOpportunities;//double
  public $Attachments;//QueryResult
  public $BudgetedCost;//double
  public $CampaignId__c;//string
  public $CampaignMemberRecordTypeId;//ID
  public $CampaignMembers;//QueryResult
  public $ChildCampaigns;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Description;//string
  public $EndDate;//date
  public $Events;//QueryResult
  public $ExpectedResponse;//double
  public $ExpectedRevenue;//double
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Feeds;//QueryResult
  public $HierarchyActualCost;//double
  public $HierarchyAmountAllOpportunities;//double
  public $HierarchyAmountWonOpportunities;//double
  public $HierarchyBudgetedCost;//double
  public $HierarchyExpectedRevenue;//double
  public $HierarchyNumberOfContacts;//int
  public $HierarchyNumberOfConvertedLeads;//int
  public $HierarchyNumberOfLeads;//int
  public $HierarchyNumberOfOpportunities;//int
  public $HierarchyNumberOfResponses;//int
  public $HierarchyNumberOfWonOpportunities;//int
  public $HierarchyNumberSent;//double
  public $IsActive;//boolean
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Leads;//QueryResult
  public $Name;//string
  public $NumberOfContacts;//int
  public $NumberOfConvertedLeads;//int
  public $NumberOfLeads;//int
  public $NumberOfOpportunities;//int
  public $NumberOfResponses;//int
  public $NumberOfWonOpportunities;//int
  public $NumberSent;//double
  public $OpenActivities;//QueryResult
  public $Opportunities;//QueryResult
  public $Owner;//User
  public $OwnerId;//ID
  public $Parent;//Campaign
  public $ParentId;//ID
  public $PrimaryLeads__r;//QueryResult
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Shares;//QueryResult
  public $StartDate;//date
  public $Status;//string
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
  public $Type;//string
}

class sfdc_CampaignFeed {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//Campaign
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_CampaignMember {
  public $Campaign;//Campaign
  public $CampaignId;//ID
  public $Contact;//Contact
  public $ContactId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FirstRespondedDate;//date
  public $HasResponded;//boolean
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Lead;//Lead
  public $LeadId;//ID
  public $Status;//string
  public $SystemModstamp;//dateTime
}

class sfdc_CampaignMemberStatus {
  public $CampaignId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $HasResponded;//boolean
  public $IsDefault;//boolean
  public $IsDeleted;//boolean
  public $Label;//string
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $SortOrder;//int
  public $SystemModstamp;//dateTime
}

class sfdc_CampaignShare {
  public $Campaign;//Campaign
  public $CampaignAccessLevel;//string
  public $CampaignId;//ID
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $RowCause;//string
  public $UserOrGroupId;//ID
}

class sfdc_SupportCase {
  public $Account;//Account
  public $AccountId;//ID
  public $ActivityHistories;//QueryResult
  public $Application__c;//string
  public $Asset;//Asset
  public $AssetId;//ID
  public $Assoc_Product_ID__c;//string
  public $Attachments;//QueryResult
  public $BusinessHours;//BusinessHours
  public $BusinessHoursId;//ID
  public $Cable_Manuf__c;//string
  public $Cable_Type__c;//string
  public $CaseComments;//QueryResult
  public $CaseContactRoles;//QueryResult
  public $CaseMilestones;//QueryResult
  public $CaseNumber;//string
  public $CaseSolutions;//QueryResult
  public $Case_Created_from_Email__c;//boolean
  public $Cases;//QueryResult
  public $Cases__r;//QueryResult
  public $Clicktools_test__c;//string
  public $ClosedDate;//dateTime
  public $Closed_Status__c;//string
  public $Completed_Date__c;//date
  public $Contact;//Contact
  public $ContactId;//ID
  public $Contact_Mailing_Address__c;//string
  public $Contact_Phone_Extension__c;//string
  public $Copper_Connector__c;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Customer_Comments__c;//string
  public $Customer_Satisfied__c;//string
  public $Days_Open_Category__c;//string
  public $Days_Open__c;//double
  public $Description;//string
  public $ESV__c;//string
  public $EmailMessages;//QueryResult
  public $Email_Bounced_Date__c;//date
  public $Email_Bounced_Reason__c;//string
  public $Entitlement;//Entitlement
  public $EntitlementId;//ID
  public $Escalated__c;//boolean
  public $Estimated_Completion_Date_2__c;//date
  public $Estimated_Completion_Date__c;//date
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Feeds;//QueryResult
  public $Fiber_Connector__c;//string
  public $Fwd_Database__c;//string
  public $Gold_Number2__c;//string
  public $HasCommentsUnreadByOwner;//boolean
  public $HasSelfServiceComments;//boolean
  public $Histories;//QueryResult
  public $ISV__c;//string
  public $IncidentId__c;//string
  public $Incident_ID__c;//string
  public $Internal_Submitter__c;//ID
  public $Internal_Submitter__r;//User
  public $IsClosed;//boolean
  public $IsClosedOnCreate;//boolean
  public $IsDeleted;//boolean
  public $IsEscalated;//boolean
  public $IsSelfServiceClosed;//boolean
  public $IsStopped;//boolean
  public $IsVisibleInSelfService;//boolean
  public $Key_Code_Serial__c;//string
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Layer3__c;//string
  public $MIB__c;//string
  public $Manufacturer__c;//string
  public $MilestoneStatus;//string
  public $Model_Number_Comment__c;//string
  public $Model_Number__c;//string
  public $Model__c;//string
  public $New_Email_Received__c;//boolean
  public $OM_Status__c;//string
  public $OS__c;//string
  public $OpenActivities;//QueryResult
  public $Order_Number__c;//string
  public $Origin;//string
  public $Other_Mfg_Mdl_Ver__c;//string
  public $Owner;//Name
  public $OwnerId;//ID
  public $Package_Carrier_1__c;//string
  public $Package_Carrier_2__c;//string
  public $Package_Carrier_3__c;//string
  public $Package_Carrier_4__c;//string
  public $Package_Carrier_5__c;//string
  public $Parent;//Case
  public $ParentId;//ID
  public $Parent_Case__c;//ID
  public $Parent_Case__r;//Case
  public $Platform__c;//string
  public $Priority;//string
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Product;//Product2
  public $ProductId;//ID
  public $Product_Group__c;//string
  public $Product__c;//string
  public $Reason;//string
  public $RecordType;//RecordType
  public $RecordTypeId;//ID
  public $Requested_Completion_Date__c;//date
  public $Requestor_Address__c;//string
  public $Requestor_Email__c;//string
  public $Requestor_Name__c;//string
  public $Requestor_Phone__c;//string
  public $ResCode1__c;//string
  public $ResCode2__c;//string
  public $ResCode3__c;//string
  public $ResCode4__c;//string
  public $Routers__c;//string
  public $SDOC__SDoc_Relationships__r;//QueryResult
  public $SNMP__c;//string
  public $SVC_Status__c;//string
  public $Send_Survey__c;//boolean
  public $Shares;//QueryResult
  public $SlaExitDate;//dateTime
  public $SlaStartDate;//dateTime
  public $Solutions;//QueryResult
  public $Source__c;//string
  public $Status;//string
  public $StopStartDate;//dateTime
  public $Subject;//string
  public $SuppliedCompany;//string
  public $SuppliedEmail;//string
  public $SuppliedName;//string
  public $SuppliedPhone;//string
  public $Support_Status__c;//string
  public $Survey_Status__c;//string
  public $Switches__c;//string
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
  public $TeamMembers;//QueryResult
  public $TeamTemplateRecords;//QueryResult
  public $Test_Standard__c;//string
  public $ThreadId__c;//string
  public $Tier__c;//string
  public $Type;//string
  public $VLANs__c;//string
  public $Version__c;//string
  public $What_caused_this_issue__c;//string
  public $email_subject__c;//string
}

class sfdc_CaseComment {
  public $CommentBody;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDeleted;//boolean
  public $IsPublished;//boolean
  public $LastModifiedBy;//Name
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Parent;//Case
  public $ParentId;//ID
  public $SystemModstamp;//dateTime
}

class sfdc_CaseContactRole {
  public $Cases;//Case
  public $CasesId;//ID
  public $Contact;//Contact
  public $ContactId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Role;//string
  public $SystemModstamp;//dateTime
}

class sfdc_CaseFeed {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//Case
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_CaseHistory {
  public $Case;//Case
  public $CaseId;//ID
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
}

class sfdc_CaseMilestone {
  public $Case;//Case
  public $CaseId;//ID
  public $CompletionDate;//dateTime
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $ElapsedTimeInDays;//double
  public $ElapsedTimeInHrs;//double
  public $ElapsedTimeInMins;//int
  public $IsCompleted;//boolean
  public $IsDeleted;//boolean
  public $IsViolated;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $MilestoneType;//MilestoneType
  public $MilestoneTypeId;//ID
  public $StartDate;//dateTime
  public $SystemModstamp;//dateTime
  public $TargetDate;//dateTime
  public $TargetResponseInDays;//double
  public $TargetResponseInHrs;//double
  public $TargetResponseInMins;//int
}

class sfdc_CaseShare {
  public $Case;//Case
  public $CaseAccessLevel;//string
  public $CaseId;//ID
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $RowCause;//string
  public $UserOrGroupId;//ID
}

class sfdc_CaseSolution {
  public $Case;//Case
  public $CaseId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDeleted;//boolean
  public $Solution;//Solution
  public $SolutionId;//ID
  public $SystemModstamp;//dateTime
}

class sfdc_CaseStatus {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsClosed;//boolean
  public $IsDefault;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $MasterLabel;//string
  public $SortOrder;//int
  public $SystemModstamp;//dateTime
}

class sfdc_CaseTeamMember {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Member;//Name
  public $MemberId;//ID
  public $Parent;//Case
  public $ParentId;//ID
  public $SystemModstamp;//dateTime
  public $TeamRole;//CaseTeamRole
  public $TeamRoleId;//ID
  public $TeamTemplateMember;//CaseTeamTemplateMember
  public $TeamTemplateMemberId;//ID
}

class sfdc_CaseTeamRole {
  public $AccessLevel;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $PreferencesVisibleInCSP;//boolean
  public $SystemModstamp;//dateTime
}

class sfdc_CaseTeamTemplate {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $SystemModstamp;//dateTime
}

class sfdc_CaseTeamTemplateMember {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $MemberId;//ID
  public $SystemModstamp;//dateTime
  public $TeamRoleId;//ID
  public $TeamTemplateId;//ID
}

class sfdc_CaseTeamTemplateRecord {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Parent;//Case
  public $ParentId;//ID
  public $SystemModstamp;//dateTime
  public $TeamTemplate;//CaseTeamTemplate
  public $TeamTemplateId;//ID
}

class sfdc_CategoryData {
  public $CategoryNodeId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $RelatedSobjectId;//ID
  public $SystemModstamp;//dateTime
}

class sfdc_CategoryNode {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $MasterLabel;//string
  public $ParentId;//ID
  public $SortOrder;//int
  public $SortStyle;//string
  public $SystemModstamp;//dateTime
}

class sfdc_ChatterActivity {
  public $CommentCount;//int
  public $CommentReceivedCount;//int
  public $InfluenceRawRank;//int
  public $LikeReceivedCount;//int
  public $ParentId;//ID
  public $PostCount;//int
  public $SystemModstamp;//dateTime
}

class sfdc_ChatterConversation {
  public $ChatterMessages;//QueryResult
}

class sfdc_ChatterConversationMember {
  public $ConversationId;//ID
  public $MemberId;//ID
}

class sfdc_ChatterMessage {
  public $Body;//string
  public $Conversation;//ChatterConversation
  public $ConversationId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $SenderId;//ID
  public $SentDate;//dateTime
}

class sfdc_ClientBrowser {
  public $CreatedDate;//dateTime
  public $FullUserAgent;//string
  public $LastUpdate;//dateTime
  public $ProxyInfo;//string
  public $Users;//User
  public $UsersId;//ID
}

class sfdc_CollaborationGroup {
  public $CanHaveGuests;//boolean
  public $CollaborationType;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Feeds;//QueryResult
  public $FullPhotoUrl;//string
  public $GroupMemberRequests;//QueryResult
  public $GroupMembers;//QueryResult
  public $HasPrivateFieldsAccess;//boolean
  public $InformationBody;//string
  public $InformationTitle;//string
  public $LastFeedModifiedDate;//dateTime
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $MemberCount;//int
  public $Name;//string
  public $Owner;//User
  public $OwnerId;//ID
  public $SmallPhotoUrl;//string
  public $SystemModstamp;//dateTime
}

class sfdc_CollaborationGroupFeed {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//CollaborationGroup
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_CollaborationGroupMember {
  public $CollaborationGroup;//CollaborationGroup
  public $CollaborationGroupId;//ID
  public $CollaborationRole;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Member;//User
  public $MemberId;//ID
  public $NotificationFrequency;//string
  public $SystemModstamp;//dateTime
}

class sfdc_CollaborationGroupMemberRequest {
  public $CollaborationGroup;//CollaborationGroup
  public $CollaborationGroupId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $RequesterId;//ID
  public $ResponseMessage;//string
  public $Status;//string
  public $SystemModstamp;//dateTime
}

class sfdc_CollaborationInvitation {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $InvitedUserEmail;//string
  public $InvitedUserEmailNormalized;//string
  public $InviterId;//ID
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $OptionalMessage;//string
  public $ParentId;//ID
  public $SharedEntityId;//ID
  public $Status;//string
  public $SystemModstamp;//dateTime
}

class sfdc_Community {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $IsActive;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $SystemModstamp;//dateTime
}

class sfdc_CompanyOnyx__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//CompanyOnyx__c
  public $ParentId;//ID
}

class sfdc_CompanyOnyx__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Processed__c;//boolean
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
  public $bPrivate__c;//double
  public $bValidAddress__c;//double
  public $chCountryCode__c;//string
  public $chInsertBy__c;//string
  public $chLanguageCode__c;//string
  public $chRegionCode__c;//string
  public $chUpdateBy__c;//string
  public $dtInsertDate__c;//dateTime
  public $dtUpdateDate__c;//dateTime
  public $iAccessCode__c;//double
  public $iCompanyId__c;//string
  public $iPrimaryContactId__c;//double
  public $iSiteId__c;//double
  public $tiRecordStatus__c;//double
  public $vchAddress1__c;//string
  public $vchCity__c;//string
  public $vchCompanyName__c;//string
  public $vchPostCode__c;//string
}

class sfdc_Contact {
  public $ANPM_MQL__c;//boolean
  public $Account;//Account
  public $AccountContactRoles;//QueryResult
  public $AccountContacts__r;//QueryResult
  public $AccountId;//ID
  public $AccountId__c;//string
  public $AccountName__c;//string
  public $Account_Type__c;//string
  public $ActivityHistories;//QueryResult
  public $Additional_Comments__c;//string
  public $Appointment_Set__c;//boolean
  public $Assets;//QueryResult
  public $Assets__r;//QueryResult
  public $AssistantName;//string
  public $AssistantPhone;//string
  public $Attachments;//QueryResult
  public $Biggest_Issue__c;//string
  public $Birthdate;//date
  public $Business_Critical_Applications__c;//string
  public $Business_Driver__c;//string
  public $Business_Unit__c;//string
  public $Buying_Authority__c;//string
  public $Buying_Horizon__c;//string
  public $CSP_FTE_MQL__c;//boolean
  public $CampaignMembers;//QueryResult
  public $Campaign_Code__c;//string
  public $Campaign_Most_Recent__c;//string
  public $Campaign_Name__c;//string
  public $Campaign_Original__c;//string
  public $Campaign_Type__c;//string
  public $Campaign_at_Last_MQL__c;//string
  public $CaseContactRoles;//QueryResult
  public $Cases;//QueryResult
  public $Comments__c;//string
  public $Company_Revenue__c;//double
  public $Company__c;//string
  public $ContactLeads__r;//QueryResult
  public $Contact_Me__c;//boolean
  public $Contact_Role__c;//string
  public $ContractContactRoles;//QueryResult
  public $ContractsSigned;//QueryResult
  public $Covered_Gold_Support__c;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Current_Appl_Netwrk_Perfrmnce_Tool__c;//string
  public $DCI_COPPER_MQL__c;//boolean
  public $DCI_FIBER_Channel_MQL__c;//boolean
  public $DCI_FIBER_MQL__c;//boolean
  public $Demographic_Score__c;//double
  public $Department;//string
  public $Description;//string
  public $Device_Users__r;//QueryResult
  public $DoNotCall;//boolean
  public $Do_Not_Count__c;//boolean
  public $Email;//string
  public $EmailBouncedDate;//dateTime
  public $EmailBouncedReason;//string
  public $EmailStatuses;//QueryResult
  public $EntitlementContacts;//QueryResult
  public $EventRelations;//QueryResult
  public $Events;//QueryResult
  public $Ext__c;//string
  public $FNET_Key_Account__c;//boolean
  public $Fax;//string
  public $Federal_MQL__c;//boolean
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Feeds;//QueryResult
  public $FirstName;//string
  public $Former_Employee__c;//boolean
  public $Funded_IT_Projects_Initiatives__c;//string
  public $GOLD_MQL__c;//boolean
  public $Gold_Number__c;//string
  public $Gold_PIN__c;//string
  public $Government_Entity__c;//string
  public $HasOptedOutOfEmail;//boolean
  public $HasOptedOutOfFax;//boolean
  public $Histories;//QueryResult
  public $HomePhone;//string
  public $How_many_fiber_strands_do_you_have__c;//string
  public $IncidentId__c;//string
  public $IndividualId__c;//string
  public $Infrastructure_Vendors__c;//string
  public $Interest_inAirMagnet_Planner__c;//boolean
  public $Interest_inAirMagnet_Spectrum_XT__c;//boolean
  public $Interest_in_APA__c;//boolean
  public $Interest_in_ASE__c;//boolean
  public $Interest_in_AirCheck__c;//boolean
  public $Interest_in_AirMagnet_Enterprise__c;//boolean
  public $Interest_in_AirMagnet_Survey__c;//boolean
  public $Interest_in_AirMagnet_VoFi_Analyzer__c;//boolean
  public $Interest_in_AirMagnet_WiFi_Analyzer__c;//boolean
  public $Interest_in_AirMapper__c;//boolean
  public $Interest_in_AirMedic_USB__c;//boolean
  public $Interest_in_CertiFiber_Pro__c;//boolean
  public $Interest_in_Clearsight_Analyzer__c;//boolean
  public $Interest_in_DSX_CableAnalyzer__c;//boolean
  public $Interest_in_DTX__c;//boolean
  public $Interest_in_Etherscope__c;//boolean
  public $Interest_in_LinkRunner__c;//boolean
  public $Interest_in_LinkSprinter_100__c;//boolean
  public $Interest_in_LinkSprinter_200__c;//boolean
  public $Interest_in_LinkWare__c;//boolean
  public $Interest_in_NPM_Suite__c;//boolean
  public $Interest_in_NTM__c;//boolean
  public $Interest_in_NetFlow_Tracker__c;//boolean
  public $Interest_in_NetTool__c;//boolean
  public $Interest_in_OmniPoint__c;//boolean
  public $Interest_in_OneTouch__c;//boolean
  public $Interest_in_OptiView_XG__c;//boolean
  public $Interest_in_Optifiber_PRO__c;//boolean
  public $Interest_in_Optiview__c;//boolean
  public $Interest_in_TruView_Live__c;//boolean
  public $Interest_in_TruView__c;//boolean
  public $Interest_in_UpTime__c;//boolean
  public $Interest_in_VPM_Connex__c;//boolean
  public $Interest_in_VPM_Express__c;//boolean
  public $Interest_in_VPM__c;//boolean
  public $Interest_in_Versiv__c;//boolean
  public $IsDeleted;//boolean
  public $Jigsaw;//string
  public $JigsawContactId;//string
  public $Job_Role__c;//string
  public $Language_Preference__c;//string
  public $LastActivityDate;//date
  public $LastCURequestDate;//dateTime
  public $LastCUUpdateDate;//dateTime
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $LastName;//string
  public $Last_Active_Opportunity__c;//ID
  public $Last_Active_Opportunity__r;//Opportunity
  public $Last_Campaign__c;//string
  public $Last_MQL_Date__c;//dateTime
  public $LeadSource;//string
  public $Lead_Priority__c;//string
  public $Lead_Source_Detail__c;//string
  public $Lead_Source_Most_Recent__c;//string
  public $Lead_Source_Original__c;//string
  public $Life_Cycle_Stage__c;//string
  public $Literature_Fullfillment_Code__c;//string
  public $Located_at_IT_HQ__c;//string
  public $MQL_Histories__r;//QueryResult
  public $MailingCity;//string
  public $MailingCountry;//string
  public $MailingLatitude;//double
  public $MailingLongitude;//double
  public $MailingPostalCode;//string
  public $MailingState;//string
  public $MailingStreet;//string
  public $MailingStreet2__c;//string
  public $Mainframe_Serial_Number__c;//string
  public $Managed_Service_Customer__c;//boolean
  public $MasterRecord;//Contact
  public $MasterRecordId;//ID
  public $MobilePhone;//string
  public $Most_Critical__c;//string
  public $MyAccount_Customer__c;//boolean
  public $My_primary_area_of_responsibility__c;//string
  public $My_primary_networking_issue__c;//string
  public $My_primary_networking_project__c;//string
  public $Name;//string
  public $Network_Analyzer__c;//boolean
  public $Network_Nodes__c;//string
  public $Next_Steps__c;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Number_Network_Nodes__c;//string
  public $Number_of_Sites__c;//string
  public $OpenActivities;//QueryResult
  public $Opportunities;//QueryResult
  public $Opportunities__r;//QueryResult
  public $OpportunityContactRoles;//QueryResult
  public $OpportunityContactRoles__r;//QueryResult
  public $OrderContactRoles__r;//QueryResult
  public $OtherCity;//string
  public $OtherCountry;//string
  public $OtherLatitude;//double
  public $OtherLongitude;//double
  public $OtherPhone;//string
  public $OtherPostalCode;//string
  public $OtherState;//string
  public $OtherStreet;//string
  public $Owner;//User
  public $OwnerId;//ID
  public $Owns_APA__c;//boolean
  public $Owns_ASE__c;//boolean
  public $Owns_AirCheck__c;//boolean
  public $Owns_AirMagnet_Enterprise__c;//boolean
  public $Owns_AirMagnet_Planner__c;//boolean
  public $Owns_AirMagnet_Spectrum_XT__c;//boolean
  public $Owns_AirMagnet_Survey__c;//boolean
  public $Owns_AirMagnet_VoFi_Analyzer__c;//boolean
  public $Owns_AirMagnet_WiFi_Analyzer__c;//boolean
  public $Owns_AirMapper__c;//boolean
  public $Owns_AirMedic_USB__c;//boolean
  public $Owns_CertiFiber_Pro__c;//boolean
  public $Owns_DSX_CableAnalyzer__c;//boolean
  public $Owns_DTX__c;//boolean
  public $Owns_Etherscope__c;//boolean
  public $Owns_LinkRunner__c;//boolean
  public $Owns_LinkSprinter_100__c;//boolean
  public $Owns_LinkSprinter_200__c;//boolean
  public $Owns_NPM_Suite__c;//boolean
  public $Owns_NTM__c;//boolean
  public $Owns_NetFlow_Tracker__c;//boolean
  public $Owns_NetTool__c;//boolean
  public $Owns_OmniPoint__c;//boolean
  public $Owns_OneTouch__c;//boolean
  public $Owns_OptiFiberPro__c;//boolean
  public $Owns_OptiView_XG__c;//boolean
  public $Owns_TruView_Live__c;//boolean
  public $Owns_TruView__c;//boolean
  public $Owns_UpTime__c;//boolean
  public $Owns_VPM_Connex__c;//boolean
  public $Owns_VPM_Express__c;//boolean
  public $Owns_VPM__c;//boolean
  public $Owns_Versiv__c;//boolean
  public $PNA_Optiview_MQL__c;//boolean
  public $PNA_Optiview_Marketing_Qualified_Lead__c;//boolean
  public $PNT_AirCheck_MQL__c;//boolean
  public $PNT_MQL__c;//boolean
  public $PNT_OneTouch_MQL__c;//boolean
  public $Persona__c;//boolean
  public $Phone;//string
  public $Pre_MQL__c;//boolean
  public $Primary_Key__c;//string
  public $Priority__c;//string
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $ProdFAM_A_MQL__c;//boolean
  public $ProdFAM_B_MQL__c;//boolean
  public $ProdFAM_C_MQL__c;//boolean
  public $ProductId__c;//string
  public $Product_Family_MQL__c;//string
  public $Product_Model__c;//string
  public $Project_Size__c;//string
  public $Purchase_Month__c;//string
  public $Purchase_Year__c;//string
  public $Quotes;//QueryResult
  public $ReportsTo;//Contact
  public $ReportsToId;//ID
  public $Request_a_free_5_day_LAN_WLAN_network_an__c;//boolean
  public $SDOC__SDoc_Relationships__r;//QueryResult
  public $Salutation;//string
  public $Satisfaction_Level__c;//string
  public $Satisfied_with_your_tool__c;//string
  public $Self_Managed_Direct_Customer__c;//boolean
  public $ServiceContracts;//QueryResult
  public $Service_Contracts__r;//QueryResult
  public $Shares;//QueryResult
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
  public $Telecommunications_Provider__c;//string
  public $Time_to_address_these_Concerns__c;//string
  public $Timeframe__c;//string
  public $Title;//string
  public $Tracking_Code__c;//string
  public $Understands_Value_Proposition__c;//boolean
  public $UseSalesforce;//string
  public $Use_Case__c;//string
  public $Using_LinkWare__c;//string
  public $VNS_NTM_MQL__c;//boolean
  public $VNS_VPM_HIGH_MQL__c;//boolean
  public $WLAN_Carrier_MQL__c;//boolean
  public $WLAN_Enterprise_MQL__c;//boolean
  public $WLAN_Federal_MQL__c;//boolean
  public $WLAN_Mobile_MQL__c;//boolean
  public $WLAN_infrastructure_vendor__c;//string
  public $mkto2__Inferred_City__c;//string
  public $mkto2__Inferred_Company__c;//string
  public $mkto2__Inferred_Country__c;//string
  public $mkto2__Inferred_Metropolitan_Area__c;//string
  public $mkto2__Inferred_Phone_Area_Code__c;//string
  public $mkto2__Inferred_Postal_Code__c;//string
  public $mkto2__Inferred_State_Region__c;//string
  public $mkto2__Lead_Score__c;//double
  public $mkto2__Original_Referrer__c;//string
  public $mkto2__Original_Search_Engine__c;//string
  public $mkto2__Original_Search_Phrase__c;//string
  public $mkto2__Original_Source_Info__c;//string
  public $mkto2__Original_Source_Type__c;//string
  public $mkto_si__HideDate__c;//date
  public $mkto_si__Last_Interesting_Moment_Date__c;//dateTime
  public $mkto_si__Last_Interesting_Moment_Desc__c;//string
  public $mkto_si__Last_Interesting_Moment_Source__c;//string
  public $mkto_si__Last_Interesting_Moment_Type__c;//string
  public $mkto_si__Last_Interesting_Moment__c;//string
  public $mkto_si__Leads__r;//QueryResult
  public $mkto_si__Priority__c;//double
  public $mkto_si__Relative_Score_Value__c;//double
  public $mkto_si__Relative_Score__c;//string
  public $mkto_si__Sales_Insight__c;//string
  public $mkto_si__Urgency_Value__c;//double
  public $mkto_si__Urgency__c;//string
  public $mkto_si__View_in_Marketo__c;//string
  public $mkto_si__WebActivityCache__r;//QueryResult
  public $qbdialer__Dialer_Query_Items__r;//QueryResult
  public $qbdialer__Dials__c;//double
  public $qbdialer__LastCallTime__c;//dateTime
  public $qbdialer__ResponseTime__c;//double
  public $qbdialer__Seek_Initiative_Items__r;//QueryResult
}

class sfdc_ContactFeed {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//Contact
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_ContactHistory {
  public $Contact;//Contact
  public $ContactId;//ID
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
}

class sfdc_ContactLead__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//ContactLead__c
  public $ParentId;//ID
}

class sfdc_ContactLead__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $Contact__c;//ID
  public $Contact__r;//Contact
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Lead__c;//ID
  public $Lead__r;//Lead
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Product__c;//string
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_ContactShare {
  public $Contact;//Contact
  public $ContactAccessLevel;//string
  public $ContactId;//ID
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $RowCause;//string
  public $UserOrGroupId;//ID
}

class sfdc_ContentDocument {
  public $ArchivedById;//ID
  public $ArchivedDate;//date
  public $ContentDocumentLinks;//QueryResult
  public $ContentVersions;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Feeds;//QueryResult
  public $Histories;//QueryResult
  public $IsArchived;//boolean
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $LatestPublishedVersion;//ContentVersion
  public $LatestPublishedVersionId;//ID
  public $Owner;//User
  public $OwnerId;//ID
  public $PublishStatus;//string
  public $SystemModstamp;//dateTime
  public $Title;//string
}

class sfdc_ContentDocumentFeed {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//ContentDocument
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_ContentDocumentHistory {
  public $ContentDocument;//ContentDocument
  public $ContentDocumentId;//ID
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
}

class sfdc_ContentDocumentLink {
  public $ContentDocument;//ContentDocument
  public $ContentDocumentId;//ID
  public $IsDeleted;//boolean
  public $LinkedEntity;//Name
  public $LinkedEntityId;//ID
  public $ShareType;//string
  public $SystemModstamp;//dateTime
  public $Visibility;//string
}

class sfdc_ContentVersion {
  public $Checksum;//string
  public $ContentDocument;//ContentDocument
  public $ContentDocumentId;//ID
  public $ContentLocation;//string
  public $ContentModifiedById;//ID
  public $ContentModifiedDate;//dateTime
  public $ContentSize;//int
  public $ContentUrl;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Description;//string
  public $ExternalDataSource;//ExternalDataSource
  public $ExternalDataSourceId;//ID
  public $ExternalDocumentInfo1;//string
  public $ExternalDocumentInfo2;//string
  public $FeaturedContentBoost;//int
  public $FeaturedContentDate;//date
  public $FileType;//string
  public $FirstPublishLocation;//Name
  public $FirstPublishLocationId;//ID
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $IsLatest;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $NegativeRatingCount;//int
  public $Origin;//string
  public $Owner;//User
  public $OwnerId;//ID
  public $PathOnClient;//string
  public $PositiveRatingCount;//int
  public $PublishStatus;//string
  public $RatingCount;//int
  public $ReasonForChange;//string
  public $SystemModstamp;//dateTime
  public $TagCsv;//string
  public $Title;//string
  public $VersionData;//base64Binary
  public $VersionNumber;//string
}

class sfdc_ContentVersionHistory {
  public $ContentVersion;//ContentVersion
  public $ContentVersionId;//ID
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
}

class sfdc_Contract {
  public $Account;//Account
  public $AccountId;//ID
  public $ActivatedBy;//User
  public $ActivatedById;//ID
  public $ActivatedDate;//dateTime
  public $ActivityHistories;//QueryResult
  public $Approvals;//QueryResult
  public $Attachments;//QueryResult
  public $BillingCity;//string
  public $BillingCountry;//string
  public $BillingLatitude;//double
  public $BillingLongitude;//double
  public $BillingPostalCode;//string
  public $BillingState;//string
  public $BillingStreet;//string
  public $CompanySigned;//User
  public $CompanySignedDate;//date
  public $CompanySignedId;//ID
  public $ContractContactRoles;//QueryResult
  public $ContractNumber;//string
  public $ContractTerm;//int
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $CustomerSigned;//Contact
  public $CustomerSignedDate;//date
  public $CustomerSignedId;//ID
  public $CustomerSignedTitle;//string
  public $Description;//string
  public $EndDate;//date
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Feeds;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastApprovedDate;//dateTime
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Opportunities;//QueryResult
  public $Orders;//QueryResult
  public $Owner;//User
  public $OwnerExpirationNotice;//string
  public $OwnerId;//ID
  public $Pricebook2;//Pricebook2
  public $Pricebook2Id;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Quotes;//QueryResult
  public $SDOC__SDoc_Relationships__r;//QueryResult
  public $ShippingCity;//string
  public $ShippingCountry;//string
  public $ShippingLatitude;//double
  public $ShippingLongitude;//double
  public $ShippingPostalCode;//string
  public $ShippingState;//string
  public $ShippingStreet;//string
  public $SpecialTerms;//string
  public $StartDate;//date
  public $Status;//string
  public $StatusCode;//string
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_ContractContactRole {
  public $Contact;//Contact
  public $ContactId;//ID
  public $Contract;//Contract
  public $ContractId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDeleted;//boolean
  public $IsPrimary;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Role;//string
  public $SystemModstamp;//dateTime
}

class sfdc_ContractFeed {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//Contract
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_ContractHistory {
  public $Contract;//Contract
  public $ContractId;//ID
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
}

class sfdc_ContractLineItem {
  public $AMS_ProductFamilyId__c;//string
  public $AMS_ProductFamilyName__c;//string
  public $ActivityHistories;//QueryResult
  public $Asset;//Asset
  public $AssetId;//ID
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Description;//string
  public $Discount;//double
  public $EndDate;//date
  public $Entitlements;//QueryResult
  public $Events;//QueryResult
  public $Gold_Contact__c;//string
  public $Gold_Contract_Type__c;//string
  public $Gold_Model__c;//string
  public $Gold_Product_Code__c;//string
  public $Histories;//QueryResult
  public $Incident_ID__c;//string
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $LineItemNumber;//string
  public $ListPrice;//double
  public $Main_Unit__c;//boolean
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Onyx_Account_Id__c;//string
  public $OpenActivities;//QueryResult
  public $Opportunity_Product__r;//QueryResult
  public $Order_Products__r;//QueryResult
  public $PricebookEntry;//PricebookEntry
  public $PricebookEntryId;//ID
  public $Pricebook_Price__c;//double
  public $Product2;//Product2
  public $ProductForecastGroupCode__c;//string
  public $Product_Name_Model_Group_Code__c;//string
  public $Quantity;//double
  public $Serial_Number__c;//string
  public $ServiceContract;//ServiceContract
  public $ServiceContractId;//ID
  public $StartDate;//date
  public $Status;//string
  public $Subtotal;//double
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
  public $TotalPrice;//double
  public $UnitPrice;//double
}

class sfdc_ContractLineItemHistory {
  public $ContractLineItem;//ContractLineItem
  public $ContractLineItemId;//ID
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
}

class sfdc_ContractStatus {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDefault;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $MasterLabel;//string
  public $SortOrder;//int
  public $StatusCode;//string
  public $SystemModstamp;//dateTime
}

class sfdc_CronTrigger {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CronExpression;//string
  public $EndTime;//dateTime
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $NextFireTime;//dateTime
  public $OwnerId;//ID
  public $PreviousFireTime;//dateTime
  public $StartTime;//dateTime
  public $State;//string
  public $TimeZoneSidKey;//string
  public $TimesTriggered;//int
}

class sfdc_CurrencyType {
  public $ConversionRate;//double
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $DecimalPlaces;//int
  public $IsActive;//boolean
  public $IsCorporate;//boolean
  public $IsoCode;//string
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $SystemModstamp;//dateTime
}

class sfdc_CustomConsoleComponent {
  public $AbsoluteHeight;//int
  public $AbsoluteWidth;//int
  public $ButtonIconUrl;//string
  public $ButtonStyle;//string
  public $ButtonText;//string
  public $ButtonWidth;//int
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $DeveloperName;//string
  public $IsDeleted;//boolean
  public $IsHeightFixed;//boolean
  public $IsHidden;//boolean
  public $IsPopoutDisabled;//boolean
  public $IsWidthFixed;//boolean
  public $Language;//string
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $MasterLabel;//string
  public $NamespacePrefix;//string
  public $RelativeHeight;//double
  public $RelativeWidth;//double
  public $SystemModstamp;//dateTime
  public $VisualforcePage;//ApexPage
  public $VisualforcePageId;//ID
}

class sfdc_CustomerProductOnyx2__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//CustomerProductOnyx2__c
  public $ParentId;//ID
}

class sfdc_CustomerProductOnyx2__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Processed__c;//boolean
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
  public $chInsertBy__c;//string
  public $chLanguageCode__c;//string
  public $chProductNumber__c;//string
  public $chUpdateBy__c;//string
  public $dtInsertDate__c;//dateTime
  public $dtPurchaseDate__c;//date
  public $dtUpdateDate__c;//dateTime
  public $flQuantity__c;//double
  public $iAccessCode__c;//double
  public $iContactId__c;//string
  public $iOwnerId__c;//string
  public $iProductId__c;//string
  public $iSiteId__c;//double
  public $tiRecordStatus__c;//double
  public $vchSerialNumber__c;//string
  public $vchUser7__c;//date
}

class sfdc_CustomerProductOnyx__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//CustomerProductOnyx__c
  public $ParentId;//ID
}

class sfdc_CustomerProductOnyx__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Processed__c;//boolean
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
  public $chInsertBy__c;//string
  public $chLanguageCode__c;//string
  public $chProductNumber__c;//string
  public $chUpdateBy__c;//string
  public $dtInsertDate__c;//dateTime
  public $dtPurchaseDate__c;//date
  public $dtUpdateDate__c;//dateTime
  public $flQuantity__c;//double
  public $iAccessCode__c;//double
  public $iContactId__c;//string
  public $iOwnerId__c;//string
  public $iProductId__c;//string
  public $iSiteId__c;//double
  public $tiRecordStatus__c;//double
  public $vchSerialNumber__c;//string
  public $vchUser7__c;//date
}

class sfdc_CustomerProductSFDC__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//CustomerProductSFDC__c
  public $ParentId;//ID
}

class sfdc_CustomerProductSFDC__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Error__c;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Processed__c;//boolean
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
  public $chProductNumber__c;//string
  public $dtPurchaseDate__c;//date
  public $iContactId__c;//string
  public $iOwnerId__c;//string
  public $iProductId__c;//string
  public $vchSerialNumber__c;//string
}

class sfdc_Dashboard {
  public $BackgroundDirection;//string
  public $BackgroundEnd;//int
  public $BackgroundStart;//int
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $DashboardComponents;//QueryResult
  public $Description;//string
  public $DeveloperName;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Feeds;//QueryResult
  public $Folder;//Folder
  public $FolderId;//ID
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $LeftSize;//string
  public $MiddleSize;//string
  public $NamespacePrefix;//string
  public $RightSize;//string
  public $RunningUser;//User
  public $RunningUserId;//ID
  public $SystemModstamp;//dateTime
  public $TextColor;//int
  public $Title;//string
  public $TitleColor;//int
  public $TitleSize;//int
  public $Type;//string
}

class sfdc_DashboardComponent {
  public $Dashboard;//Dashboard
  public $DashboardId;//ID
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Feeds;//QueryResult
  public $Name;//string
}

class sfdc_DashboardComponentFeed {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//DashboardComponent
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_DashboardFeed {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//Dashboard
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_DatedConversionRate {
  public $ConversionRate;//double
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsoCode;//string
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $NextStartDate;//date
  public $StartDate;//date
  public $SystemModstamp;//dateTime
}

class sfdc_Device_User__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//Device_User__c
  public $ParentId;//ID
}

class sfdc_Device_User__c {
  public $ActivityHistories;//QueryResult
  public $Asset__c;//ID
  public $Asset__r;//Asset
  public $Attachments;//QueryResult
  public $Contact__c;//ID
  public $Contact__r;//Contact
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_Document {
  public $Author;//User
  public $AuthorId;//ID
  public $Body;//base64Binary
  public $BodyLength;//int
  public $ContentType;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $DeveloperName;//string
  public $Folder;//Folder
  public $FolderId;//ID
  public $IsBodySearchable;//boolean
  public $IsDeleted;//boolean
  public $IsInternalUseOnly;//boolean
  public $IsPublic;//boolean
  public $Keywords;//string
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $NamespacePrefix;//string
  public $SystemModstamp;//dateTime
  public $Type;//string
  public $Url;//string
}

class sfdc_DocumentAttachmentMap {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $DocumentId;//ID
  public $DocumentSequence;//int
  public $ParentId;//ID
}

class sfdc_Domain {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Domain;//string
  public $DomainSites;//QueryResult
  public $DomainType;//string
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $SystemModstamp;//dateTime
}

class sfdc_DomainSite {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Domain;//Domain
  public $DomainId;//ID
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $PathPrefix;//string
  public $Site;//Site
  public $SiteId;//ID
  public $SystemModstamp;//dateTime
}

class sfdc_EmailMessage {
  public $ActivityId;//ID
  public $Attachments;//QueryResult
  public $BccAddress;//string
  public $CcAddress;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FromAddress;//string
  public $FromName;//string
  public $HasAttachment;//boolean
  public $Headers;//string
  public $HtmlBody;//string
  public $Incoming;//boolean
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $MessageDate;//dateTime
  public $Parent;//Case
  public $ParentId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $ReplyToEmailMessage;//EmailMessage
  public $ReplyToEmailMessageId;//ID
  public $Status;//string
  public $Subject;//string
  public $SystemModstamp;//dateTime
  public $TextBody;//string
  public $ToAddress;//string
}

class sfdc_EmailServicesAddress {
  public $AuthorizedSenders;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $EmailDomainName;//string
  public $Function;//EmailServicesFunction
  public $FunctionId;//ID
  public $IsActive;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $LocalPart;//string
  public $RunAsUserId;//ID
  public $SystemModstamp;//dateTime
}

class sfdc_EmailServicesFunction {
  public $AddressInactiveAction;//string
  public $Addresses;//QueryResult
  public $ApexClassId;//ID
  public $AttachmentOption;//string
  public $AuthenticationFailureAction;//string
  public $AuthorizationFailureAction;//string
  public $AuthorizedSenders;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $ErrorRoutingAddress;//string
  public $FunctionInactiveAction;//string
  public $FunctionName;//string
  public $IsActive;//boolean
  public $IsAuthenticationRequired;//boolean
  public $IsErrorRoutingEnabled;//boolean
  public $IsTextAttachmentsAsBinary;//boolean
  public $IsTlsRequired;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $OverLimitAction;//string
  public $SystemModstamp;//dateTime
}

class sfdc_EmailStatus {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $EmailTemplateName;//string
  public $FirstOpenDate;//dateTime
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $LastOpenDate;//dateTime
  public $Task;//Task
  public $TaskId;//ID
  public $TimesOpened;//int
  public $Who;//Name
  public $WhoId;//ID
}

class sfdc_EmailTemplate {
  public $ApiVersion;//double
  public $Attachments;//QueryResult
  public $Body;//string
  public $BrandTemplateId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $DeveloperName;//string
  public $Encoding;//string
  public $Folder;//Folder
  public $FolderId;//ID
  public $HtmlValue;//string
  public $IsActive;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $LastUsedDate;//dateTime
  public $Markup;//string
  public $Name;//string
  public $NamespacePrefix;//string
  public $Owner;//User
  public $OwnerId;//ID
  public $Subject;//string
  public $SystemModstamp;//dateTime
  public $TemplateStyle;//string
  public $TemplateType;//string
  public $TimesUsed;//int
}

class sfdc_Entitlement {
  public $Account;//Account
  public $AccountId;//ID
  public $ActivityHistories;//QueryResult
  public $Asset;//Asset
  public $AssetId;//ID
  public $Attachments;//QueryResult
  public $BusinessHours;//BusinessHours
  public $BusinessHoursId;//ID
  public $Cases;//QueryResult
  public $CasesPerEntitlement;//int
  public $ContractLineItem;//ContractLineItem
  public $ContractLineItemId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $EndDate;//date
  public $EntitlementContacts;//QueryResult
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Feeds;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $IsPerIncident;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $RemainingCases;//int
  public $ServiceContract;//ServiceContract
  public $ServiceContractId;//ID
  public $SlaProcess;//SlaProcess
  public $SlaProcessId;//ID
  public $StartDate;//date
  public $Status;//string
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
  public $Type;//string
}

class sfdc_EntitlementContact {
  public $Contact;//Contact
  public $ContactId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Entitlement;//Entitlement
  public $EntitlementId;//ID
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $SystemModstamp;//dateTime
}

class sfdc_EntitlementFeed {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//Entitlement
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_EntitlementHistory {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Entitlement;//Entitlement
  public $EntitlementId;//ID
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
}

class sfdc_EntitlementTemplate {
  public $BusinessHoursId;//ID
  public $CasesPerEntitlement;//int
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsPerIncident;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $SlaProcessId;//ID
  public $SystemModstamp;//dateTime
  public $Term;//int
  public $Type;//string
}

class sfdc_EntitySubscription {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDeleted;//boolean
  public $Parent;//Name
  public $ParentId;//ID
  public $Subscriber;//User
  public $SubscriberId;//ID
}

class sfdc_Event {
  public $Account;//Account
  public $AccountId;//ID
  public $ActivityDate;//date
  public $ActivityDateTime;//dateTime
  public $ActivityId__c;//string
  public $Activity_Result__c;//string
  public $Attachments;//QueryResult
  public $ClientGuid;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Delta_in_minutes__c;//double
  public $Description;//string
  public $DurationInMinutes;//int
  public $EVAL_Model__c;//string
  public $EVAL_Order_Status__c;//string
  public $EVAL_Purchase_Date__c;//date
  public $EVAL_Return_Date__c;//date
  public $EVAL_Serial_Number__c;//string
  public $EVAL_Ship_Date__c;//date
  public $EndDateTime;//dateTime
  public $EventRelations;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Feeds;//QueryResult
  public $GroupEventType;//string
  public $IsAllDayEvent;//boolean
  public $IsArchived;//boolean
  public $IsChild;//boolean
  public $IsClientManaged;//boolean
  public $IsDeleted;//boolean
  public $IsException;//boolean
  public $IsGroupEvent;//boolean
  public $IsPrivate;//boolean
  public $IsRecurrence;//boolean
  public $IsReminderSet;//boolean
  public $IsVisibleInSelfService;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Location;//string
  public $OriginalInstanceDateTime;//dateTime
  public $Owner;//Name
  public $OwnerId;//ID
  public $RecurrenceActivityId;//ID
  public $RecurrenceDayOfMonth;//int
  public $RecurrenceDayOfWeekMask;//int
  public $RecurrenceEndDateOnly;//date
  public $RecurrenceInstance;//string
  public $RecurrenceInterval;//int
  public $RecurrenceMonthOfYear;//string
  public $RecurrenceStartDateTime;//dateTime
  public $RecurrenceTimeZoneSidKey;//string
  public $RecurrenceType;//string
  public $RecurringEvents;//QueryResult
  public $ReminderDateTime;//dateTime
  public $ShowAs;//string
  public $StartDateTime;//dateTime
  public $Subject;//string
  public $SystemModstamp;//dateTime
  public $Type;//string
  public $What;//Name
  public $WhatId;//ID
  public $Who;//Name
  public $WhoId;//ID
  public $qbdialer__CallRecordingURL__c;//string
  public $qbdialer__Call_Date_Time__c;//dateTime
  public $qbdialer__Call_Dial_Number__c;//double
  public $qbdialer__Call_Hour__c;//string
  public $qbdialer__Call_Lead_Status__c;//string
  public $qbdialer__Call_Ring_Time__c;//double
  public $qbdialer__Call_Time_Zone__c;//string
  public $qbdialer__Callback_Date_Time__c;//dateTime
  public $qbdialer__ImpressionId__c;//double
  public $qbdialer__SMSReminder__c;//boolean
}

class sfdc_EventFeed {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//Event
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_EventRecurrenceException {
  public $ActivityDateOriginal;//dateTime
  public $ActivityDateTimeOriginal;//dateTime
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $EventId;//ID
  public $IsAllDayEventOriginal;//boolean
  public $IsDeletion;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $RecurrenceEventId;//ID
  public $SystemModstamp;//dateTime
}

class sfdc_EventRelation {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Event;//Event
  public $EventId;//ID
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Relation;//Name
  public $RelationId;//ID
  public $RespondedDate;//dateTime
  public $Response;//string
  public $Status;//string
  public $SystemModstamp;//dateTime
}

class sfdc_ExternalDataSource {
  public $ApiKey;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $DeveloperName;//string
  public $Endpoint;//string
  public $IsDeleted;//boolean
  public $Language;//string
  public $LargeIcon;//StaticResource
  public $LargeIconId;//ID
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $MasterLabel;//string
  public $NamespacePrefix;//string
  public $PrincipalType;//string
  public $Repository;//string
  public $SetupEntityAccessItems;//QueryResult
  public $SmallIcon;//StaticResource
  public $SmallIconId;//ID
  public $SystemModstamp;//dateTime
  public $Type;//string
  public $UserAuths;//QueryResult
}

class sfdc_ExternalDataUserAuth {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $ExternalDataSource;//Name
  public $ExternalDataSourceId;//ID
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Password;//string
  public $Protocol;//string
  public $SystemModstamp;//dateTime
  public $User;//User
  public $UserId;//ID
  public $Username;//string
}

class sfdc_FNET_Custom_Settings__c {
  public $Auto_Gold_Renewal__c;//string
  public $BccEmail__c;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $InsertCRMCaseQueue__c;//string
  public $InsertSupportCaseQueue__c;//string
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Marketo_API_Userid__c;//string
  public $Name;//string
  public $Onyx_Sync_UserId__c;//string
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Sales_Generated__c;//string
  public $SetupOwner;//Name
  public $SetupOwnerId;//ID
  public $SystemModstamp;//dateTime
}

class sfdc_FeedComment {
  public $CommentBody;//string
  public $CommentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedItemId;//ID
  public $InsertedBy;//User
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $ParentId;//ID
  public $RelatedRecordId;//ID
}

class sfdc_FeedItem {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//Name
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_FeedLike {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedEntityId;//ID
  public $FeedItemId;//ID
  public $InsertedBy;//User
  public $InsertedById;//ID
  public $IsDeleted;//boolean
}

class sfdc_FeedTrackedChange {
  public $CurrencyIsoCode;//string
  public $FeedItemId;//ID
  public $FieldName;//string
  public $NewValue;//anyType
  public $OldCurrencyIsoCode;//string
  public $OldValue;//anyType
}

class sfdc_FieldPermissions {
  public $Field;//string
  public $Parent;//PermissionSet
  public $ParentId;//ID
  public $PermissionsEdit;//boolean
  public $PermissionsRead;//boolean
  public $SobjectType;//string
  public $SystemModstamp;//dateTime
}

class sfdc_Field_Trip__Field_Analysis__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//Field_Trip__Field_Analysis__c
  public $ParentId;//ID
}

class sfdc_Field_Trip__Field_Analysis__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Field_Trip__Field_Created_Date__c;//date
  public $Field_Trip__Label__c;//string
  public $Field_Trip__Object_Analysis__c;//ID
  public $Field_Trip__Object_Analysis__r;//Field_Trip__Object_Analysis__c
  public $Field_Trip__Populated_On_Percent__c;//double
  public $Field_Trip__Populated_On__c;//double
  public $Field_Trip__Total_Tally__c;//double
  public $Field_Trip__Type__c;//string
  public $Field_Trip__isCustom__c;//boolean
  public $Field_Trip__isRequired__c;//boolean
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
}

class sfdc_Field_Trip__Object_Analysis__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//Field_Trip__Object_Analysis__c
  public $ParentId;//ID
}

class sfdc_Field_Trip__Object_Analysis__Share {
  public $AccessLevel;//string
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Parent;//Field_Trip__Object_Analysis__c
  public $ParentId;//ID
  public $RowCause;//string
  public $UserOrGroupId;//ID
}

class sfdc_Field_Trip__Object_Analysis__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Field_Trip__Field_Analyses__r;//QueryResult
  public $Field_Trip__Fields__c;//double
  public $Field_Trip__Filter__c;//string
  public $Field_Trip__Last_Analyzed__c;//dateTime
  public $Field_Trip__Last_Batch_Id__c;//string
  public $Field_Trip__Object_Label__c;//string
  public $Field_Trip__Object_Name__c;//string
  public $Field_Trip__Record_Types__c;//double
  public $Field_Trip__Records__c;//double
  public $Field_Trip__Tally__c;//double
  public $Field_Trip__isCustom__c;//boolean
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Shares;//QueryResult
  public $SystemModstamp;//dateTime
}

class sfdc_FiscalYearSettings {
  public $Description;//string
  public $EndDate;//date
  public $IsStandardYear;//boolean
  public $Name;//string
  public $PeriodId;//ID
  public $PeriodLabelScheme;//string
  public $PeriodPrefix;//string
  public $Periods;//QueryResult
  public $QuarterLabelScheme;//string
  public $QuarterPrefix;//string
  public $StartDate;//date
  public $SystemModstamp;//dateTime
  public $WeekLabelScheme;//string
  public $WeekStartDay;//int
  public $YearType;//string
}

class sfdc_Folder {
  public $AccessType;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $DeveloperName;//string
  public $IsReadonly;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $NamespacePrefix;//string
  public $SystemModstamp;//dateTime
  public $Type;//string
}

class sfdc_ForecastShare {
  public $AccessLevel;//string
  public $CanSubmit;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $RowCause;//string
  public $UserOrGroupId;//ID
  public $UserRoleId;//ID
}

class sfdc_Gold_Email_Template__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//Gold_Email_Template__c
  public $ParentId;//ID
}

class sfdc_Gold_Email_Template__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $Language__c;//string
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
  public $Template__c;//string
  public $Type__c;//string
}

class sfdc_Group {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $DelegatedUsers;//QueryResult
  public $DeveloperName;//string
  public $DoesIncludeBosses;//boolean
  public $DoesSendEmailToMembers;//boolean
  public $Email;//string
  public $GroupMembers;//QueryResult
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Owner;//Name
  public $OwnerId;//ID
  public $QueueSobjects;//QueryResult
  public $RelatedId;//ID
  public $SystemModstamp;//dateTime
  public $Type;//string
}

class sfdc_GroupMember {
  public $Group;//Group
  public $GroupId;//ID
  public $SystemModstamp;//dateTime
  public $UserOrGroupId;//ID
}

class sfdc_HashtagDefinition {
  public $CreatedDate;//dateTime
  public $HashtagCount;//int
  public $Name;//string
  public $NameNorm;//string
  public $SystemModstamp;//dateTime
}

class sfdc_Holiday {
  public $ActivityDate;//date
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $EndTimeInMinutes;//int
  public $IsAllDay;//boolean
  public $IsRecurrence;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $RecurrenceDayOfMonth;//int
  public $RecurrenceDayOfWeekMask;//int
  public $RecurrenceEndDateOnly;//date
  public $RecurrenceInstance;//string
  public $RecurrenceInterval;//int
  public $RecurrenceMonthOfYear;//string
  public $RecurrenceStartDate;//date
  public $RecurrenceType;//string
  public $StartTimeInMinutes;//int
  public $SystemModstamp;//dateTime
}

class sfdc_Idea {
  public $Body;//string
  public $Categories;//string
  public $Comments;//QueryResult
  public $Community;//Community
  public $CommunityId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $IsDeleted;//boolean
  public $IsHtml;//boolean
  public $IsMerged;//boolean
  public $LastComment;//IdeaComment
  public $LastCommentDate;//dateTime
  public $LastCommentId;//ID
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $NumComments;//int
  public $ParentIdea;//Idea
  public $ParentIdeaId;//ID
  public $RecordType;//RecordType
  public $RecordTypeId;//ID
  public $Status;//string
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $VoteScore;//double
  public $VoteTotal;//double
  public $Votes;//QueryResult
}

class sfdc_IdeaComment {
  public $CommentBody;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Idea;//Idea
  public $IdeaId;//ID
  public $IsDeleted;//boolean
  public $IsHtml;//boolean
  public $SystemModstamp;//dateTime
  public $Votes;//QueryResult
}

class sfdc_IndividualOnyx__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//IndividualOnyx__c
  public $ParentId;//ID
}

class sfdc_IndividualOnyx__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Processed__c;//boolean
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
  public $bPrivate__c;//double
  public $bValidAddress__c;//double
  public $chCountryCode__c;//string
  public $chInsertBy__c;//string
  public $chLanguageCode__c;//string
  public $chRegionCode__c;//string
  public $chTitleCode__c;//string
  public $chUpdateBy__c;//string
  public $dtInsertDate__c;//dateTime
  public $dtUpdateDate__c;//dateTime
  public $iAccessCode__c;//double
  public $iCompanyId2__c;//string
  public $iCompanyId__c;//string
  public $iIndividualId__c;//string
  public $iSiteId__c;//double
  public $tiRecordStatus__c;//double
  public $vchCity__c;//string
  public $vchCompanyName__c;//string
  public $vchEmailAddress__c;//string
  public $vchFirstName__c;//string
  public $vchLastName__c;//string
  public $vchPhoneNumber__c;//string
  public $vchPostCode__c;//string
  public $vchTitleDesc__c;//string
}

class sfdc_Lead {
  public $ANPM_MQL__c;//boolean
  public $ActivityHistories;//QueryResult
  public $Additional_Comments__c;//string
  public $Address_Help__c;//string
  public $AnnualRevenue;//double
  public $Appointment_Set__c;//boolean
  public $Attachments;//QueryResult
  public $Auto_Routed__c;//boolean
  public $Biggest_Issue__c;//string
  public $Business_Critical_Applications__c;//string
  public $Business_Driver__c;//string
  public $Buying_Authority__c;//string
  public $Buying_Horizon__c;//string
  public $CSP_FTE_MQL__c;//boolean
  public $Campaign;//Campaign
  public $CampaignMembers;//QueryResult
  public $Campaign_Most_Recent__c;//string
  public $Campaign_Original__c;//string
  public $Campaign_at_Last_MQL__c;//string
  public $City;//string
  public $Comments__c;//string
  public $Company;//string
  public $Company_Revenue__c;//double
  public $ContactLeads__r;//QueryResult
  public $Contact_Me__c;//boolean
  public $Contact_Role__c;//string
  public $ConvertedAccount;//Account
  public $ConvertedAccountId;//ID
  public $ConvertedContact;//Contact
  public $ConvertedContactId;//ID
  public $ConvertedDate;//date
  public $ConvertedOpportunity;//Opportunity
  public $ConvertedOpportunityId;//ID
  public $Converted_By__c;//ID
  public $Converted_By__r;//User
  public $Country;//string
  public $Covered_Gold_Support__c;//string
  public $CreateCampaignMember__c;//boolean
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Current_Appl_Netwrk_Perfrmnce_Tool__c;//string
  public $DCI_COPPER_MQL__c;//boolean
  public $DCI_FIBER_Channel_MQL__c;//boolean
  public $DCI_FIBER_MQL__c;//boolean
  public $Demographic_Score__c;//double
  public $Description;//string
  public $DoNotCall;//boolean
  public $Do_Not_Count__c;//boolean
  public $Email;//string
  public $EmailBouncedDate;//dateTime
  public $EmailBouncedReason;//string
  public $EmailStatuses;//QueryResult
  public $EventRelations;//QueryResult
  public $Events;//QueryResult
  public $Fax;//string
  public $Federal_MQL__c;//boolean
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Feeds;//QueryResult
  public $FirstName;//string
  public $Funded_IT_Projects_Initiatives__c;//string
  public $GOLD_MQL__c;//boolean
  public $HasOptedOutOfEmail;//boolean
  public $HasOptedOutOfFax;//boolean
  public $Histories;//QueryResult
  public $How_many_fiber_strands_do_you_have__c;//string
  public $IncidentId__c;//string
  public $Incident_ID__c;//string
  public $Incident_Product__c;//string
  public $Incident_Status__c;//string
  public $IndividualId__c;//string
  public $Industry;//string
  public $Infrastructure_Vendors__c;//string
  public $Initial_MQL__c;//string
  public $Interest_inAirMagnet_Planner__c;//boolean
  public $Interest_inAirMagnet_Spectrum_XT__c;//boolean
  public $Interest_in_APA__c;//boolean
  public $Interest_in_ASE__c;//boolean
  public $Interest_in_AirCheck__c;//boolean
  public $Interest_in_AirMagnet_Enterprise__c;//boolean
  public $Interest_in_AirMagnet_Survey__c;//boolean
  public $Interest_in_AirMagnet_VoFi_Analyzer__c;//boolean
  public $Interest_in_AirMagnet_WiFi_Analyzer__c;//boolean
  public $Interest_in_AirMapper__c;//boolean
  public $Interest_in_AirMedic_USB__c;//boolean
  public $Interest_in_CertiFiber_Pro__c;//boolean
  public $Interest_in_Clearsight_Analyzer__c;//boolean
  public $Interest_in_DSX_CableAnalyzer__c;//boolean
  public $Interest_in_DTX__c;//boolean
  public $Interest_in_Etherscope__c;//boolean
  public $Interest_in_LinkRunner__c;//boolean
  public $Interest_in_LinkSprinter_100__c;//boolean
  public $Interest_in_LinkSprinter_200__c;//boolean
  public $Interest_in_LinkWare__c;//boolean
  public $Interest_in_NPM_Suite__c;//boolean
  public $Interest_in_NTM__c;//boolean
  public $Interest_in_NetFlow_Tracker__c;//boolean
  public $Interest_in_NetTool__c;//boolean
  public $Interest_in_OmniPoint__c;//boolean
  public $Interest_in_OneTouch__c;//boolean
  public $Interest_in_OptiView_XG__c;//boolean
  public $Interest_in_Optifiber_PRO__c;//boolean
  public $Interest_in_Optiview__c;//boolean
  public $Interest_in_TruView_Live__c;//boolean
  public $Interest_in_TruView__c;//boolean
  public $Interest_in_UpTime__c;//boolean
  public $Interest_in_VPM_Connex__c;//boolean
  public $Interest_in_VPM_Express__c;//boolean
  public $Interest_in_VPM__c;//boolean
  public $Interest_in_Versiv__c;//boolean
  public $IsConverted;//boolean
  public $IsDeleted;//boolean
  public $IsUnreadByOwner;//boolean
  public $Jigsaw;//string
  public $JigsawContactId;//string
  public $Job_Role__c;//string
  public $Key_Product_Family__c;//string
  public $Language_Preference__c;//string
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $LastName;//string
  public $LastTransferDate;//date
  public $Last_Campaign__c;//string
  public $Last_MQL_Date__c;//dateTime
  public $Last_MQL__c;//string
  public $Latitude;//double
  public $LeadLeads1__r;//QueryResult
  public $LeadLeads__r;//QueryResult
  public $LeadSource;//string
  public $Lead_Priority__c;//string
  public $Lead_Source_Detail__c;//string
  public $Lead_Source_Most_Recent__c;//string
  public $Lead_Source_Original__c;//string
  public $Life_Cycle_Stage__c;//string
  public $Literature_Fullfillment_Code__c;//string
  public $Longitude;//double
  public $MQL_Histories__r;//QueryResult
  public $MSILeadId__c;//ID
  public $MSILeadId__r;//Lead
  public $MSILeads__r;//QueryResult
  public $Mainframe_Serial_Number__c;//string
  public $Managed_Service_Customer__c;//boolean
  public $MasterRecord;//Lead
  public $MasterRecordId;//ID
  public $MobilePhone;//string
  public $Month__c;//string
  public $Most_Critical__c;//string
  public $My_primary_area_of_responsibility__c;//string
  public $My_primary_networking_issue__c;//string
  public $My_primary_networking_project__c;//string
  public $Name;//string
  public $Network_Nodes__c;//string
  public $Next_Steps__c;//string
  public $NotNetNew_Read_Only__c;//boolean
  public $NotNetNew__c;//boolean
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $NumberOfEmployees;//int
  public $Number_of_Sites__c;//string
  public $OnyxInsertBy__c;//string
  public $OnyxUpdateBy__c;//string
  public $Onyx_Insert_Date__c;//date
  public $Onyx_Last_Update_Date__c;//date
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $Owns_APA__c;//boolean
  public $Owns_ASE__c;//boolean
  public $Owns_AirCheck__c;//boolean
  public $Owns_AirMagnet_Enterprise__c;//boolean
  public $Owns_AirMagnet_Planner__c;//boolean
  public $Owns_AirMagnet_Spectrum_XT__c;//boolean
  public $Owns_AirMagnet_Survey__c;//boolean
  public $Owns_AirMagnet_VoFi_Analyzer__c;//boolean
  public $Owns_AirMagnet_WiFi_Analyzer__c;//boolean
  public $Owns_AirMapper__c;//boolean
  public $Owns_AirMedic_USB__c;//boolean
  public $Owns_CertiFiber_Pro__c;//boolean
  public $Owns_DSX_CableAnalyzer__c;//boolean
  public $Owns_DTX__c;//boolean
  public $Owns_Etherscope__c;//boolean
  public $Owns_LinkRunner__c;//boolean
  public $Owns_LinkSprinter_100__c;//boolean
  public $Owns_LinkSprinter_200__c;//boolean
  public $Owns_NPM_Suite__c;//boolean
  public $Owns_NTM__c;//boolean
  public $Owns_NetFlow_Tracker__c;//boolean
  public $Owns_NetTool__c;//boolean
  public $Owns_OmniPoint__c;//boolean
  public $Owns_OneTouch__c;//boolean
  public $Owns_OptiFiberPro__c;//boolean
  public $Owns_OptiView_XG__c;//boolean
  public $Owns_TruView_Live__c;//boolean
  public $Owns_TruView__c;//boolean
  public $Owns_UpTime__c;//boolean
  public $Owns_VPM_Connex__c;//boolean
  public $Owns_VPM_Express__c;//boolean
  public $Owns_VPM__c;//boolean
  public $Owns_Versiv__c;//boolean
  public $PNA_Optiview_MQL__c;//boolean
  public $PNT_AirCheck_MQL__c;//boolean
  public $PNT_MQL__c;//boolean
  public $PNT_OneTouch_MQL__c;//boolean
  public $PartnerAccount;//Account
  public $PartnerAccountId;//ID
  public $Persona__c;//boolean
  public $Phone;//string
  public $PostalCode;//string
  public $Pre_MQL__c;//boolean
  public $PrimaryCampaignCreateTime__c;//dateTime
  public $PrimaryCampaign__c;//ID
  public $PrimaryCampaign__r;//Campaign
  public $Primary_Product__c;//string
  public $Priority__c;//string
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $ProdFAM_A_MQL__c;//boolean
  public $ProdFAM_B_MQL__c;//boolean
  public $ProdFAM_C_MQL__c;//boolean
  public $ProductId__c;//string
  public $Product_Family_MQL__c;//string
  public $Product_Model__c;//string
  public $Project_Size__c;//string
  public $Purchase_Month__c;//string
  public $Purchase_Year__c;//string
  public $Rating;//string
  public $Reason_for_Recycle__c;//string
  public $Request_a_free_5_day_LAN_WLAN_network_an__c;//boolean
  public $SDOC__SDoc_Relationships__r;//QueryResult
  public $Sales_Region_Info__c;//string
  public $Sales_Region__c;//ID
  public $Sales_Region__r;//Ref_Country_to_Sales_Region__c
  public $Salutation;//string
  public $Satisfaction_Level__c;//string
  public $Satisfied_with_your_tool__c;//string
  public $Self_Managed_Direct_Customer__c;//boolean
  public $Shares;//QueryResult
  public $State;//string
  public $Status;//string
  public $Street;//string
  public $SystemModstamp;//dateTime
  public $TVL_MQL__c;//boolean
  public $Tasks;//QueryResult
  public $Telecommunications_Provider__c;//string
  public $Time_to_address_these_Concerns__c;//string
  public $Timeframe__c;//string
  public $Title;//string
  public $Tracking_Code_Type__c;//string
  public $Tracking_Code__c;//string
  public $Tracking_Name__c;//string
  public $Understands_Value_Proposition__c;//boolean
  public $Use_Case__c;//string
  public $Using_LinkWare__c;//string
  public $VNS_NTM_MQL__c;//boolean
  public $VNS_VPM_HIGH_MQL__c;//boolean
  public $WLAN_Carrier_MQL__c;//boolean
  public $WLAN_Enterprise_MQL__c;//boolean
  public $WLAN_Federal_MQL__c;//boolean
  public $WLAN_Mobile_MQL__c;//boolean
  public $WLAN_infrastructure_vendor__c;//string
  public $Website;//string
  public $Year__c;//double
  public $mkto2__Inferred_City__c;//string
  public $mkto2__Inferred_Company__c;//string
  public $mkto2__Inferred_Country__c;//string
  public $mkto2__Inferred_Metropolitan_Area__c;//string
  public $mkto2__Inferred_Phone_Area_Code__c;//string
  public $mkto2__Inferred_Postal_Code__c;//string
  public $mkto2__Inferred_State_Region__c;//string
  public $mkto2__Lead_Score__c;//double
  public $mkto2__Original_Referrer__c;//string
  public $mkto2__Original_Search_Engine__c;//string
  public $mkto2__Original_Search_Phrase__c;//string
  public $mkto2__Original_Source_Info__c;//string
  public $mkto2__Original_Source_Type__c;//string
  public $mkto_si__HideDate__c;//date
  public $mkto_si__Last_Interesting_Moment_Date__c;//dateTime
  public $mkto_si__Last_Interesting_Moment_Desc__c;//string
  public $mkto_si__Last_Interesting_Moment_Source__c;//string
  public $mkto_si__Last_Interesting_Moment_Type__c;//string
  public $mkto_si__Last_Interesting_Moment__c;//string
  public $mkto_si__MSIContactId__c;//ID
  public $mkto_si__MSIContactId__r;//Contact
  public $mkto_si__Priority__c;//double
  public $mkto_si__Relative_Score_Value__c;//double
  public $mkto_si__Relative_Score__c;//string
  public $mkto_si__Urgency_Value__c;//double
  public $mkto_si__Urgency__c;//string
  public $mkto_si__View_in_Marketo__c;//string
  public $mkto_si__WebActivityCache__r;//QueryResult
  public $qbdialer__Dialer_Query_Items__r;//QueryResult
  public $qbdialer__Dials__c;//double
  public $qbdialer__LastCallTime__c;//dateTime
  public $qbdialer__ResponseTime__c;//double
  public $qbdialer__Seek_Initiative_Items__r;//QueryResult
}

class sfdc_LeadFeed {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//Lead
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_LeadHistory {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $Lead;//Lead
  public $LeadId;//ID
  public $NewValue;//anyType
  public $OldValue;//anyType
}

class sfdc_LeadLead__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//LeadLead__c
  public $ParentId;//ID
}

class sfdc_LeadLead__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $Child_Lead__c;//ID
  public $Child_Lead__r;//Lead
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $Initial_MQL__c;//string
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Last_MQL__c;//string
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $Parent_Lead__c;//ID
  public $Parent_Lead__r;//Lead
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Product__c;//string
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_LeadShare {
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Lead;//Lead
  public $LeadAccessLevel;//string
  public $LeadId;//ID
  public $RowCause;//string
  public $UserOrGroupId;//ID
}

class sfdc_LeadStatus {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsConverted;//boolean
  public $IsDefault;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $MasterLabel;//string
  public $SortOrder;//int
  public $SystemModstamp;//dateTime
}

class sfdc_LineitemOverride {
  public $AmountInherited;//boolean
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $ForecastCategoryInherited;//boolean
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $OpportunityId;//ID
  public $OpportunityLineItemId;//ID
  public $OverrideAmount;//double
  public $OverrideForecastCategory;//string
  public $OverrideQuantity;//double
  public $OverrideUnitPrice;//double
  public $Owner;//User
  public $OwnerId;//ID
  public $QuantityInherited;//boolean
  public $SystemModstamp;//dateTime
  public $UnitPriceInherited;//boolean
}

class sfdc_LoginHistory {
  public $ApiType;//string
  public $ApiVersion;//string
  public $Application;//string
  public $Browser;//string
  public $ClientVersion;//string
  public $LoginTime;//dateTime
  public $LoginType;//string
  public $LoginUrl;//string
  public $Platform;//string
  public $SourceIp;//string
  public $Status;//string
  public $UserId;//ID
}

class sfdc_LoginIp {
  public $ChallengeSentDate;//dateTime
  public $CreatedDate;//dateTime
  public $IsAuthenticated;//boolean
  public $SourceIp;//string
  public $Users;//User
  public $UsersId;//ID
}

class sfdc_MQL_History__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//MQL_History__c
  public $ParentId;//ID
}

class sfdc_MQL_History__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $Contact__c;//ID
  public $Contact__r;//Contact
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Lead__c;//ID
  public $Lead__r;//Lead
  public $MQL__c;//string
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_MailmergeTemplate {
  public $Body;//base64Binary
  public $BodyLength;//int
  public $Category;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $Filename;//string
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $LastUsedDate;//dateTime
  public $Name;//string
  public $SystemModstamp;//dateTime
}

class sfdc_MilestoneType {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $SystemModstamp;//dateTime
}

class sfdc_Name {
  public $Alias;//string
  public $Email;//string
  public $FirstName;//string
  public $IsActive;//boolean
  public $LastName;//string
  public $Name;//string
  public $Phone;//string
  public $Profile;//Profile
  public $ProfileId;//ID
  public $Title;//string
  public $Type;//string
  public $UserRole;//UserRole
  public $UserRoleId;//ID
  public $Username;//string
}

class sfdc_Note {
  public $Body;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDeleted;//boolean
  public $IsPrivate;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Owner;//User
  public $OwnerId;//ID
  public $Parent;//Name
  public $ParentId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
}

class sfdc_NoteAndAttachment {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDeleted;//boolean
  public $IsNote;//boolean
  public $IsPrivate;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Owner;//User
  public $OwnerId;//ID
  public $Parent;//Name
  public $ParentId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
}

class sfdc_ObjectPermissions {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Parent;//PermissionSet
  public $ParentId;//ID
  public $PermissionsCreate;//boolean
  public $PermissionsDelete;//boolean
  public $PermissionsEdit;//boolean
  public $PermissionsModifyAllRecords;//boolean
  public $PermissionsRead;//boolean
  public $PermissionsViewAllRecords;//boolean
  public $SobjectType;//string
  public $SystemModstamp;//dateTime
}

class sfdc_OnyxAccountSequence__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//OnyxAccountSequence__c
  public $ParentId;//ID
}

class sfdc_OnyxAccountSequence__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Sequence__c;//double
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_OnyxAssetSequence__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//OnyxAssetSequence__c
  public $ParentId;//ID
}

class sfdc_OnyxAssetSequence__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Sequence__c;//double
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_OnyxContactSequence__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//OnyxContactSequence__c
  public $ParentId;//ID
}

class sfdc_OnyxContactSequence__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Sequence__c;//double
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_OpenActivity {
  public $Account;//Account
  public $AccountId;//ID
  public $ActivityDate;//date
  public $ActivityId__c;//string
  public $ActivityType;//string
  public $Activity_Result__c;//string
  public $CallDisposition;//string
  public $CallDurationInSeconds;//int
  public $CallObject;//string
  public $CallType;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Delta_in_minutes__c;//double
  public $Description;//string
  public $DurationInMinutes;//int
  public $EVAL_Model__c;//string
  public $EVAL_Order_Status__c;//string
  public $EVAL_Purchase_Date__c;//date
  public $EVAL_Return_Date__c;//date
  public $EVAL_Serial_Number__c;//string
  public $EVAL_Ship_Date__c;//date
  public $EndDateTime;//dateTime
  public $IsAllDayEvent;//boolean
  public $IsClosed;//boolean
  public $IsDeleted;//boolean
  public $IsReminderSet;//boolean
  public $IsTask;//boolean
  public $IsVisibleInSelfService;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Location;//string
  public $Owner;//Name
  public $OwnerId;//ID
  public $Priority;//string
  public $ReminderDateTime;//dateTime
  public $Status;//string
  public $Subject;//string
  public $SystemModstamp;//dateTime
  public $What;//Name
  public $WhatId;//ID
  public $Who;//Name
  public $WhoId;//ID
  public $qbdialer__CallRecordingURL__c;//string
  public $qbdialer__Call_Date_Time__c;//dateTime
  public $qbdialer__Call_Dial_Number__c;//double
  public $qbdialer__Call_Hour__c;//string
  public $qbdialer__Call_Lead_Status__c;//string
  public $qbdialer__Call_Ring_Time__c;//double
  public $qbdialer__Call_Time_Zone__c;//string
  public $qbdialer__Callback_Date_Time__c;//dateTime
  public $qbdialer__ImpressionId__c;//double
  public $qbdialer__SMSReminder__c;//boolean
}

class sfdc_Opportunity {
  public $Account;//Account
  public $AccountId;//ID
  public $AccountPartners;//QueryResult
  public $Account_Country__c;//string
  public $Account_Postal_Code__c;//string
  public $ActivityHistories;//QueryResult
  public $Additional_Follow_up_Required_If_s_What__c;//string
  public $Amount;//double
  public $Appointment_Set__c;//boolean
  public $Attachments;//QueryResult
  public $Business_Critical_Applications__c;//string
  public $Business_Driver__c;//string
  public $Business_Issue_Notes__c;//string
  public $Business_Issue__c;//string
  public $Business_Overview_Summary__c;//string
  public $Campaign;//Campaign
  public $CampaignId;//ID
  public $Challenger_Business_Goals__c;//string
  public $Challenger_Oppty_Qualification_Required__c;//string
  public $Challenger_What_Change_is_Occurring__c;//string
  public $CloseDate;//date
  public $Comments__c;//string
  public $Compelling_Event_Notes__c;//string
  public $Compelling_Event__c;//string
  public $Competition_Who_is_incumbent__c;//string
  public $Complete_Date__c;//date
  public $ContactId__c;//string
  public $Contact_Count__c;//double
  public $Contact_Role__c;//string
  public $Contacts__r;//QueryResult
  public $Converted_By__c;//ID
  public $Converted_By__r;//User
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Current_Network_Application_Summary__c;//string
  public $Date_of_Order__c;//date
  public $Days_to_Close_after_POC__c;//double
  public $Deal_Registration_Help__c;//string
  public $Decision_Making_Criteria_Economic__c;//string
  public $Decision_Making_Criteria_Technical__c;//string
  public $Decision_Making_Process__c;//string
  public $Define_Procurement_process_steps_inclu__c;//string
  public $Description;//string
  public $Evaluation_Notes_Comments__c;//string
  public $Events;//QueryResult
  public $Executive_Data_Review_Scheduled__c;//date
  public $ExpectedRevenue;//double
  public $FNET_ERP_PO__c;//string
  public $FNET_ERP_Sales_Order__c;//string
  public $FNET_Points_of_Difference__c;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Feeds;//QueryResult
  public $Final_Registration_Status__c;//string
  public $Final_Review_Date__c;//dateTime
  public $Financial_Impact__c;//string
  public $ForecastCategory;//string
  public $ForecastCategoryName;//string
  public $Gold_Contract_Type__c;//string
  public $Gold_Model_Name_del__c;//string
  public $Gold_Model__c;//ID
  public $Gold_Model__r;//Product2
  public $Gold_Number__c;//string
  public $Gold_Opportunity__c;//boolean
  public $Gold_PIN__c;//string
  public $Gold_Product_Count__c;//double
  public $HasOpportunityLineItem;//boolean
  public $Has_budget_owner_given_verbal_approval__c;//string
  public $Histories;//QueryResult
  public $Incident_ID__c;//string
  public $Incident_Product__c;//string
  public $Incident_Status__c;//string
  public $Incumbent_Name__c;//string
  public $Incumbent_is_Other_enter_name__c;//string
  public $Infrastructure_Vendors__c;//string
  public $Install_Date__c;//date
  public $IsClosed;//boolean
  public $IsDeleted;//boolean
  public $IsPrivate;//boolean
  public $IsWon;//boolean
  public $Key_Player_Consensus__c;//string
  public $Key_Product_Family_Code__c;//string
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $LeadSource;//string
  public $Marketing_Playbook__c;//string
  public $Month__c;//string
  public $Name;//string
  public $Network_Nodes__c;//string
  public $NextStep;//string
  public $Next_Step_Date__c;//dateTime
  public $Next_Steps__c;//string
  public $Ninety_days_to_expiry__c;//boolean
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Number_of_Products__c;//double
  public $Number_of_Sites__c;//string
  public $OnyxInsertBy__c;//string
  public $OnyxUpdateBy__c;//string
  public $Onyx_Insert_Date__c;//date
  public $Onyx_Last_Update_Date__c;//date
  public $OpenActivities;//QueryResult
  public $Opportunities_History__r;//QueryResult
  public $OpportunityCompetitors;//QueryResult
  public $OpportunityContactRoles;//QueryResult
  public $OpportunityContactRoles__r;//QueryResult
  public $OpportunityHistories;//QueryResult
  public $OpportunityLineItems;//QueryResult
  public $OpportunityOrders__r;//QueryResult
  public $OpportunityPartnersFrom;//QueryResult
  public $OpportunityTeamMembers;//QueryResult
  public $Opportunity_Id__c;//string
  public $Opportunity_LineItems__c;//string
  public $Opportunity_Owner_Manager_Mail__c;//string
  public $Opportunity_Owner_Name__c;//string
  public $Opportunity_Qualification_Required__c;//string
  public $Oppty_Qualification_Not_Required_Notes__c;//string
  public $Order_Fulfillment__c;//string
  public $Orders;//QueryResult
  public $Organizational_Impact__c;//string
  public $Owner;//User
  public $OwnerId;//ID
  public $Owner_Copy__c;//ID
  public $Owner_Copy__r;//User
  public $Owner_Email__c;//string
  public $Owner_s_Manager_Name__c;//string
  public $POC_Duration__c;//double
  public $PartnerAccount;//Account
  public $PartnerAccountId;//ID
  public $Partners;//QueryResult
  public $Phase_of_Decision_Making_Process__c;//string
  public $PoC_Eval_Complete__c;//date
  public $PoC_Evaluation_Checklist_Approved__c;//string
  public $PoC_Evaluation_Required__c;//string
  public $Previous_Stage__c;//string
  public $Pricebook2;//Pricebook2
  public $Pricebook2Id;//ID
  public $Primary_Business_Goals__c;//string
  public $Primary_Competitor__c;//string
  public $Primary_Competitor_is_Other_enter_name__c;//string
  public $Primary_Contact_Email__c;//string
  public $Primary_Contact_FirstName__c;//string
  public $Primary_Contact_LastName__c;//string
  public $Primary_Contact__c;//ID
  public $Primary_Contact__r;//Contact
  public $Primary_Product_Registration_Partner__c;//ID
  public $Primary_Product_Registration_Partner__r;//User
  public $Primary_Product__c;//string
  public $Primary_Solution_Set__c;//string
  public $Priority__c;//string
  public $Probability;//double
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Product_Count__c;//double
  public $Product_Owner_Approver_Comment__c;//string
  public $Product_Reviewer__c;//ID
  public $Product_Reviewer__r;//User
  public $Quote_Proposal_Feedback__c;//string
  public $Quote_Proposal_Presented__c;//date
  public $Quotes;//QueryResult
  public $Reason_Lost_Description__c;//string
  public $Reason_Lost__c;//string
  public $Reason_for_Opt_Out__c;//string
  public $Red_Flags__c;//string
  public $Renewal__c;//boolean
  public $Renewed__c;//boolean
  public $Request_Deal_Registration_Approval__c;//boolean
  public $Requested_Product__c;//string
  public $ResellerAssignment__c;//string
  public $SDOC__SDoc_Relationships__r;//QueryResult
  public $Sales_Ops_Approver_Comment__c;//string
  public $Sales_Playbook__c;//string
  public $Sales_Region_Info__c;//string
  public $Sales_Region__c;//string
  public $Scheduled_PoC_Date__c;//date
  public $Secondary_Competitor__c;//string
  public $Secondary_Competitor_s_Other_enter_name__c;//string
  public $Secondary_Solution_Set__c;//string
  public $Sequence_of_Events_Proposed_Accepted__c;//string
  public $Shares;//QueryResult
  public $Sixty_days_to_expiry__c;//boolean
  public $StageName;//string
  public $Summary_Letter_Sent__c;//string
  public $Supervisor_Approver_Comment__c;//string
  public $SyncedQuote;//Quote
  public $SyncedQuoteId;//ID
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
  public $Technical_Recommendation__c;//string
  public $Thirty_days_to_expiry__c;//boolean
  public $Timeframe__c;//string
  public $TotalOpportunityQuantity;//double
  public $Total_Amount_on_Order__c;//double
  public $Tracking_Code_Type__c;//string
  public $Tracking_Code__c;//string
  public $Tracking_Name__c;//string
  public $Type;//string
  public $Understands_Solution_set__c;//boolean
  public $Welcome_Email__c;//boolean
  public $What_Change_is_Occurring__c;//string
  public $What_Unique_Insights_are_You_Providing__c;//string
  public $When_is_funding_available__c;//string
  public $Who_Has_Given_Verbal_Approval__c;//string
  public $Who_Is_the_Blocker_s__c;//string
  public $Who_Is_the_Buyer_s__c;//string
  public $Who_Is_the_Mobilizer_s__c;//string
  public $Who_Is_the_Talker_s__c;//string
  public $Who_has_agreed_to_move_forward__c;//string
  public $Workflow_Approval_Alert__c;//boolean
  public $Year__c;//double
  public $Zero_days_to_expiry__c;//boolean
  public $mkto_si__MarketoAnalyzer__c;//string
  public $mkto_si__WebActivityCache__r;//QueryResult
}

class sfdc_OpportunityCompetitor {
  public $CompetitorName;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Opportunity;//Opportunity
  public $OpportunityId;//ID
  public $Strengths;//string
  public $SystemModstamp;//dateTime
  public $Weaknesses;//string
}

class sfdc_OpportunityContactRole {
  public $Contact;//Contact
  public $ContactId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDeleted;//boolean
  public $IsPrimary;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Opportunity;//Opportunity
  public $OpportunityId;//ID
  public $Role;//string
  public $SystemModstamp;//dateTime
}

class sfdc_OpportunityContactRole__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//OpportunityContactRole__c
  public $ParentId;//ID
}

class sfdc_OpportunityContactRole__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $Contact__c;//ID
  public $Contact__r;//Contact
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Opportunity__c;//ID
  public $Opportunity__r;//Opportunity
  public $Primary__c;//boolean
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Role__c;//string
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_OpportunityFeed {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//Opportunity
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_OpportunityFieldHistory {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Opportunity;//Opportunity
  public $OpportunityId;//ID
}

class sfdc_OpportunityHistory {
  public $Amount;//double
  public $CloseDate;//date
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $ExpectedRevenue;//double
  public $ForecastCategory;//string
  public $IsDeleted;//boolean
  public $Opportunity;//Opportunity
  public $OpportunityId;//ID
  public $Probability;//double
  public $StageName;//string
  public $SystemModstamp;//dateTime
}

class sfdc_OpportunityLineItem {
  public $Asset__c;//ID
  public $Asset__r;//Asset
  public $Contract_Line_Item__c;//ID
  public $Contract_Line_Item__r;//ContractLineItem
  public $Converted_to_Asset__c;//boolean
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Current_End_Date__c;//date
  public $Custom_Product__c;//ID
  public $Custom_Product__r;//Product2
  public $Description;//string
  public $Discount;//double
  public $End_Date__c;//date
  public $Formatted_End_Date__c;//string
  public $Incident_ID__c;//string
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $ListPrice;//double
  public $New__c;//boolean
  public $Opportunity;//Opportunity
  public $OpportunityId;//ID
  public $PricebookEntry;//PricebookEntry
  public $PricebookEntryId;//ID
  public $Product_Description__c;//string
  public $Product_Name__c;//string
  public $Quantity;//double
  public $Serial_Number__c;//string
  public $ServiceDate;//date
  public $SortOrder;//int
  public $Start_Date__c;//date
  public $Subtotal;//double
  public $SystemModstamp;//dateTime
  public $TotalPrice;//double
  public $UnitPrice;//double
}

class sfdc_OpportunityOrder__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//OpportunityOrder__c
  public $ParentId;//ID
}

class sfdc_OpportunityOrder__c {
  public $Account__c;//ID
  public $Account__r;//Account
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Opportunity__c;//ID
  public $Opportunity__r;//Opportunity
  public $Order__c;//ID
  public $Order__r;//Order
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_OpportunityOverride {
  public $AmountInherited;//boolean
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $ForecastCategoryInherited;//boolean
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $OpportunityId;//ID
  public $OutOfDate;//boolean
  public $OverrideAmount;//double
  public $OverrideComment;//string
  public $OverrideForecastCategory;//string
  public $OverridePeriodId;//ID
  public $OverrideQuantity;//double
  public $Owner;//User
  public $OwnerId;//ID
  public $PeriodInherited;//boolean
  public $QuantityInherited;//boolean
  public $SystemModstamp;//dateTime
}

class sfdc_OpportunityPartner {
  public $AccountTo;//Account
  public $AccountToId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDeleted;//boolean
  public $IsPrimary;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Opportunity;//Opportunity
  public $OpportunityId;//ID
  public $ReversePartnerId;//ID
  public $Role;//string
  public $SystemModstamp;//dateTime
}

class sfdc_OpportunityShare {
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Opportunity;//Opportunity
  public $OpportunityAccessLevel;//string
  public $OpportunityId;//ID
  public $RowCause;//string
  public $UserOrGroupId;//ID
}

class sfdc_OpportunityStage {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $DefaultProbability;//double
  public $Description;//string
  public $ForecastCategory;//string
  public $ForecastCategoryName;//string
  public $IsActive;//boolean
  public $IsClosed;//boolean
  public $IsWon;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $MasterLabel;//string
  public $SortOrder;//int
  public $SystemModstamp;//dateTime
}

class sfdc_OpportunityTeamMember {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Opportunity;//Opportunity
  public $OpportunityAccessLevel;//string
  public $OpportunityId;//ID
  public $SystemModstamp;//dateTime
  public $TeamMemberRole;//string
  public $User;//User
  public $UserId;//ID
}

class sfdc_Opportunity_History__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//Opportunity_History__c
  public $ParentId;//ID
}

class sfdc_Opportunity_History__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $Close_Date__c;//date
  public $Country__c;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Created_Date__c;//date
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Forecast_Category__c;//string
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Opportunity_Created_Date__c;//date
  public $Opportunity_OwnerID__c;//string
  public $Opportunity_Owner__c;//ID
  public $Opportunity_Owner__r;//User
  public $Opportunity__c;//ID
  public $Opportunity__r;//Opportunity
  public $Owner;//Name
  public $OwnerId;//ID
  public $Primary_Product__c;//string
  public $Probability__c;//double
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Sales_Region__c;//string
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_Order {
  public $Account;//Account
  public $AccountId;//ID
  public $ActivatedBy;//User
  public $ActivatedById;//ID
  public $ActivatedDate;//dateTime
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $BillToContact;//Contact
  public $BillToContactId;//ID
  public $BillingCity;//string
  public $BillingCountry;//string
  public $BillingLatitude;//double
  public $BillingLongitude;//double
  public $BillingPostalCode;//string
  public $BillingState;//string
  public $BillingStreet;//string
  public $CompanyAuthorizedBy;//User
  public $CompanyAuthorizedById;//ID
  public $CompanyAuthorizedDate;//date
  public $Contract;//Contract
  public $ContractId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $CustomerAuthorizedBy;//Contact
  public $CustomerAuthorizedById;//ID
  public $CustomerAuthorizedDate;//date
  public $Description;//string
  public $Distributor_Name__c;//string
  public $EffectiveDate;//date
  public $EndDate;//date
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Gold_Contract_Type__c;//string
  public $Gold_Number__c;//string
  public $Gold_PIN__c;//string
  public $HasOrderItem__c;//boolean
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $IsReductionOrder;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $LineItemCount__c;//double
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $OpportunityOrders__r;//QueryResult
  public $OrderContactRoles__r;//QueryResult
  public $OrderItems;//QueryResult
  public $OrderNumber;//string
  public $OrderPartners__r;//QueryResult
  public $OrderReferenceNumber;//string
  public $Orders;//QueryResult
  public $PoDate;//date
  public $PoNumber;//string
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Purchase_Order__c;//string
  public $RecordType;//RecordType
  public $RecordTypeId;//ID
  public $Renewed__c;//boolean
  public $Sales_Order__c;//string
  public $Sales_Region__c;//string
  public $ShipToContact;//Contact
  public $ShipToContactId;//ID
  public $ShippingCity;//string
  public $ShippingCountry;//string
  public $ShippingLatitude;//double
  public $ShippingLongitude;//double
  public $ShippingPostalCode;//string
  public $ShippingState;//string
  public $ShippingStreet;//string
  public $Status;//string
  public $StatusCode;//string
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
  public $TotalAmount;//double
  public $Type;//string
  public $Welcome_Email__c;//boolean
}

class sfdc_OrderContactRole__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//OrderContactRole__c
  public $ParentId;//ID
}

class sfdc_OrderContactRole__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $Contact__c;//ID
  public $Contact__r;//Contact
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Email__c;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $Language_Preference__c;//string
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Order__c;//ID
  public $Order__r;//Order
  public $Primary__c;//boolean
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Role__c;//string
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_OrderHistory {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Order;//Order
  public $OrderId;//ID
}

class sfdc_OrderItem {
  public $Asset_Contract_Match__c;//string
  public $Asset_Serial_Number__c;//string
  public $Asset__c;//ID
  public $Asset__r;//Asset
  public $ChildOrderItems;//QueryResult
  public $Contract_Line_Item__c;//ID
  public $Contract_Line_Item__r;//ContractLineItem
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Custom_Product__c;//ID
  public $Custom_Product__r;//Product2
  public $Description;//string
  public $EndDate;//date
  public $End_Date__c;//date
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Formatted_End_Date__c;//string
  public $GLD_Product__c;//boolean
  public $Gold_Contract_Type__c;//string
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $ListPrice;//double
  public $Order;//Order
  public $OrderId;//ID
  public $OrderItemNumber;//string
  public $OriginalOrderItem;//OrderItem
  public $OriginalOrderItemId;//ID
  public $PricebookEntry;//PricebookEntry
  public $PricebookEntryId;//ID
  public $Product_Description__c;//string
  public $Product_Name__c;//string
  public $Purchase_Order__c;//string
  public $Quantity;//double
  public $Sales_Order__c;//string
  public $Serial_Number__c;//string
  public $ServiceDate;//date
  public $Start_Date__c;//date
  public $SystemModstamp;//dateTime
  public $UnitPrice;//double
}

class sfdc_OrderItemHistory {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $OrderItem;//OrderItem
  public $OrderItemId;//ID
}

class sfdc_OrderPartner__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//OrderPartner__c
  public $ParentId;//ID
}

class sfdc_OrderPartner__c {
  public $Account__c;//ID
  public $Account__r;//Account
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Order__c;//ID
  public $Order__r;//Order
  public $Primary__c;//boolean
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_OrgWideEmailAddress {
  public $Address;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $DisplayName;//string
  public $IsAllowAllProfiles;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $SystemModstamp;//dateTime
}

class sfdc_Organization {
  public $City;//string
  public $ComplianceBccEmail;//string
  public $Country;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $DefaultAccountAccess;//string
  public $DefaultCalendarAccess;//string
  public $DefaultCampaignAccess;//string
  public $DefaultCaseAccess;//string
  public $DefaultContactAccess;//string
  public $DefaultLeadAccess;//string
  public $DefaultLocaleSidKey;//string
  public $DefaultOpportunityAccess;//string
  public $DefaultPricebookAccess;//string
  public $Division;//string
  public $Fax;//string
  public $FiscalYearStartMonth;//int
  public $LanguageLocaleKey;//string
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Latitude;//double
  public $Longitude;//double
  public $MonthlyPageViewsEntitlement;//int
  public $MonthlyPageViewsUsed;//int
  public $Name;//string
  public $OrganizationType;//string
  public $Phone;//string
  public $PostalCode;//string
  public $PreferencesRequireOpportunityProducts;//boolean
  public $PrimaryContact;//string
  public $ReceivesAdminInfoEmails;//boolean
  public $ReceivesInfoEmails;//boolean
  public $State;//string
  public $Street;//string
  public $SystemModstamp;//dateTime
  public $TrialExpirationDate;//dateTime
  public $UiSkin;//string
  public $UsesStartDateAsFiscalYearName;//boolean
  public $WebToCaseDefaultOrigin;//string
}

class sfdc_Partner {
  public $AccountFrom;//Account
  public $AccountFromId;//ID
  public $AccountTo;//Account
  public $AccountToId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDeleted;//boolean
  public $IsPrimary;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Opportunity;//Opportunity
  public $OpportunityId;//ID
  public $ReversePartnerId;//ID
  public $Role;//string
  public $SystemModstamp;//dateTime
}

class sfdc_PartnerRole {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $MasterLabel;//string
  public $ReverseRole;//string
  public $SortOrder;//int
  public $SystemModstamp;//dateTime
}

class sfdc_Period {
  public $EndDate;//date
  public $FiscalYearSettings;//FiscalYearSettings
  public $FiscalYearSettingsId;//ID
  public $IsForecastPeriod;//boolean
  public $Number;//int
  public $PeriodLabel;//string
  public $QuarterLabel;//string
  public $StartDate;//date
  public $SystemModstamp;//dateTime
  public $Type;//string
}

class sfdc_PermissionSet {
  public $Assignments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $FieldPerms;//QueryResult
  public $IsOwnedByProfile;//boolean
  public $Label;//string
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $NamespacePrefix;//string
  public $ObjectPerms;//QueryResult
  public $PermissionsActivateContract;//boolean
  public $PermissionsActivateOrder;//boolean
  public $PermissionsAllowEmailIC;//boolean
  public $PermissionsApiEnabled;//boolean
  public $PermissionsApiUserOnly;//boolean
  public $PermissionsAuthorApex;//boolean
  public $PermissionsBulkApiHardDelete;//boolean
  public $PermissionsCanInsertFeedSystemFields;//boolean
  public $PermissionsCanUseNewDashboardBuilder;//boolean
  public $PermissionsChatterFileLink;//boolean
  public $PermissionsChatterInternalUser;//boolean
  public $PermissionsChatterInviteExternalUsers;//boolean
  public $PermissionsChatterOwnGroups;//boolean
  public $PermissionsContentAdministrator;//boolean
  public $PermissionsConvertLeads;//boolean
  public $PermissionsCreatePackaging;//boolean
  public $PermissionsCreateWorkspaces;//boolean
  public $PermissionsCustomizeApplication;//boolean
  public $PermissionsDataExport;//boolean
  public $PermissionsDelegatedPortalUserAdmin;//boolean
  public $PermissionsDeleteActivatedContract;//boolean
  public $PermissionsDistributeFromPersWksp;//boolean
  public $PermissionsEditActivatedOrders;//boolean
  public $PermissionsEditBrandTemplates;//boolean
  public $PermissionsEditCaseComments;//boolean
  public $PermissionsEditEvent;//boolean
  public $PermissionsEditHtmlTemplates;//boolean
  public $PermissionsEditOppLineItemUnitPrice;//boolean
  public $PermissionsEditOwnQuota;//boolean
  public $PermissionsEditPublicDocuments;//boolean
  public $PermissionsEditPublicTemplates;//boolean
  public $PermissionsEditReadonlyFields;//boolean
  public $PermissionsEditReports;//boolean
  public $PermissionsEditTask;//boolean
  public $PermissionsEmailAdministration;//boolean
  public $PermissionsEmailMass;//boolean
  public $PermissionsEmailSingle;//boolean
  public $PermissionsEmailTemplateManagement;//boolean
  public $PermissionsEnableNotifications;//boolean
  public $PermissionsExportReport;//boolean
  public $PermissionsFlowUFLRequired;//boolean
  public $PermissionsIPRestrictRequests;//boolean
  public $PermissionsImportLeads;//boolean
  public $PermissionsImportPersonal;//boolean
  public $PermissionsInboundMigrationToolsUser;//boolean
  public $PermissionsInstallPackaging;//boolean
  public $PermissionsManageAnalyticSnapshots;//boolean
  public $PermissionsManageAuthProviders;//boolean
  public $PermissionsManageBusinessHourHolidays;//boolean
  public $PermissionsManageCallCenters;//boolean
  public $PermissionsManageCases;//boolean
  public $PermissionsManageCategories;//boolean
  public $PermissionsManageChatterMessages;//boolean
  public $PermissionsManageContentPermissions;//boolean
  public $PermissionsManageContentProperties;//boolean
  public $PermissionsManageContentTypes;//boolean
  public $PermissionsManageCssUsers;//boolean
  public $PermissionsManageCustomReportTypes;//boolean
  public $PermissionsManageDashboards;//boolean
  public $PermissionsManageDataCategories;//boolean
  public $PermissionsManageDataIntegrations;//boolean
  public $PermissionsManageDynamicDashboards;//boolean
  public $PermissionsManageEmailClientConfig;//boolean
  public $PermissionsManageEntitlements;//boolean
  public $PermissionsManageInteraction;//boolean
  public $PermissionsManageLeads;//boolean
  public $PermissionsManageMobile;//boolean
  public $PermissionsManageNetworks;//boolean
  public $PermissionsManagePartners;//boolean
  public $PermissionsManageRemoteAccess;//boolean
  public $PermissionsManageSelfService;//boolean
  public $PermissionsManageSolutions;//boolean
  public $PermissionsManageUsers;//boolean
  public $PermissionsMassInlineEdit;//boolean
  public $PermissionsModerateChatter;//boolean
  public $PermissionsModifyAllData;//boolean
  public $PermissionsNewReportBuilder;//boolean
  public $PermissionsOutboundMigrationToolsUser;//boolean
  public $PermissionsOverrideForecasts;//boolean
  public $PermissionsPasswordNeverExpires;//boolean
  public $PermissionsPublishPackaging;//boolean
  public $PermissionsResetPasswords;//boolean
  public $PermissionsRunFlow;//boolean
  public $PermissionsRunReports;//boolean
  public $PermissionsScheduleJob;//boolean
  public $PermissionsScheduleReports;//boolean
  public $PermissionsSendSitRequests;//boolean
  public $PermissionsSolutionImport;//boolean
  public $PermissionsTransferAnyCase;//boolean
  public $PermissionsTransferAnyEntity;//boolean
  public $PermissionsTransferAnyLead;//boolean
  public $PermissionsUseTeamReassignWizards;//boolean
  public $PermissionsViewAllData;//boolean
  public $PermissionsViewAllForecasts;//boolean
  public $PermissionsViewAllUsers;//boolean
  public $PermissionsViewContent;//boolean
  public $PermissionsViewDataCategories;//boolean
  public $PermissionsViewEncryptedData;//boolean
  public $PermissionsViewMyTeamsDashboards;//boolean
  public $PermissionsViewSetup;//boolean
  public $Profile;//Profile
  public $ProfileId;//ID
  public $SetupEntityAccessItems;//QueryResult
  public $SystemModstamp;//dateTime
  public $UserLicense;//UserLicense
  public $UserLicenseId;//ID
}

class sfdc_PermissionSetAssignment {
  public $Assignee;//User
  public $AssigneeId;//ID
  public $PermissionSet;//PermissionSet
  public $PermissionSetId;//ID
  public $SystemModstamp;//dateTime
}

class sfdc_Pricebook2 {
  public $Contracts;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Description;//string
  public $Histories;//QueryResult
  public $IsActive;//boolean
  public $IsDeleted;//boolean
  public $IsStandard;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Opportunities;//QueryResult
  public $Orders;//QueryResult
  public $PricebookEntries;//QueryResult
  public $Quotes;//QueryResult
  public $ServiceContracts;//QueryResult
  public $SystemModstamp;//dateTime
}

class sfdc_Pricebook2History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Pricebook2;//Pricebook2
  public $Pricebook2Id;//ID
}

class sfdc_PricebookEntry {
  public $ContractLineItems;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $IsActive;//boolean
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $OpportunityLineItems;//QueryResult
  public $OrderItems;//QueryResult
  public $Pricebook2;//Pricebook2
  public $Pricebook2Id;//ID
  public $Product2;//Product2
  public $Product2Id;//ID
  public $ProductCode;//string
  public $QuoteLineItems;//QueryResult
  public $SystemModstamp;//dateTime
  public $UnitPrice;//double
  public $UseStandardPrice;//boolean
}

class sfdc_ProcessDefinition {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $DeveloperName;//string
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $LockType;//string
  public $Name;//string
  public $State;//string
  public $SystemModstamp;//dateTime
  public $TableEnumOrId;//string
  public $Type;//string
}

class sfdc_ProcessInstance {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $ProcessDefinition;//ProcessDefinition
  public $ProcessDefinitionId;//ID
  public $Status;//string
  public $Steps;//QueryResult
  public $StepsAndWorkitems;//QueryResult
  public $SystemModstamp;//dateTime
  public $TargetObject;//Name
  public $TargetObjectId;//ID
  public $Workitems;//QueryResult
}

class sfdc_ProcessInstanceHistory {
  public $Actor;//Name
  public $ActorId;//ID
  public $Comments;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDeleted;//boolean
  public $IsPending;//boolean
  public $OriginalActor;//Name
  public $OriginalActorId;//ID
  public $ProcessInstance;//ProcessInstance
  public $ProcessInstanceId;//ID
  public $RemindersSent;//int
  public $StepStatus;//string
  public $SystemModstamp;//dateTime
  public $TargetObject;//Name
  public $TargetObjectId;//ID
}

class sfdc_ProcessInstanceStep {
  public $Actor;//Name
  public $ActorId;//ID
  public $Comments;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $OriginalActor;//Name
  public $OriginalActorId;//ID
  public $ProcessInstance;//ProcessInstance
  public $ProcessInstanceId;//ID
  public $StepNodeId;//ID
  public $StepStatus;//string
  public $SystemModstamp;//dateTime
}

class sfdc_ProcessInstanceWorkitem {
  public $Actor;//Name
  public $ActorId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDeleted;//boolean
  public $OriginalActor;//Name
  public $OriginalActorId;//ID
  public $ProcessInstance;//ProcessInstance
  public $ProcessInstanceId;//ID
  public $SystemModstamp;//dateTime
}

class sfdc_ProcessNode {
  public $Description;//string
  public $DeveloperName;//string
  public $Name;//string
  public $ProcessDefinition;//ProcessDefinition
  public $ProcessDefinitionId;//ID
  public $SystemModstamp;//dateTime
}

class sfdc_Product2 {
  public $AMS_Product_Family__c;//ID
  public $AMS_Product_Family__r;//AMS_Product_Family__c
  public $ActivityHistories;//QueryResult
  public $Assets;//QueryResult
  public $Attachments;//QueryResult
  public $Cases;//QueryResult
  public $Child__r;//QueryResult
  public $Comp_Category__c;//string
  public $Country_Of_Origin__c;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Description;//string
  public $End_Date_Active__c;//date
  public $Events;//QueryResult
  public $Family;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Feeds;//QueryResult
  public $Forecast_Grp_Code__c;//string
  public $Gross_Weight__c;//string
  public $Hierarchy__c;//string
  public $IsActive;//boolean
  public $IsDeleted;//boolean
  public $ItemCode__c;//string
  public $Item_Exception1__c;//string
  public $Item_Status__c;//string
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Market_Model__c;//string
  public $Model_Class__c;//string
  public $Model_Group__c;//string
  public $Model__c;//string
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Obsolete_Date__c;//date
  public $OpenActivities;//QueryResult
  public $Opportunities__r;//QueryResult
  public $Opportunity_Product__r;//QueryResult
  public $Order_Products__r;//QueryResult
  public $PGG_SGG__c;//string
  public $Parent__r;//QueryResult
  public $PricebookEntries;//QueryResult
  public $Primary_UOM_Code__c;//string
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $ProductCode;//string
  public $ProductGoldJunctions1__r;//QueryResult
  public $ProductGoldJunctions__r;//QueryResult
  public $Product_Notes__c;//string
  public $Quote_Line_Items__r;//QueryResult
  public $Registration_Code__c;//string
  public $SDOC__SDoc_Relationships__r;//QueryResult
  public $SUPP__c;//string
  public $Service_Contracts__r;//QueryResult
  public $Start_Date_Active__c;//date
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
  public $UPC__c;//string
  public $Webdisplayable__c;//boolean
  public $Webregisterable__c;//boolean
}

class sfdc_Product2Feed {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//Product2
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_ProductEntitlementTemplate {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $EntitlementTemplateId;//ID
  public $Product2Id;//ID
  public $SystemModstamp;//dateTime
}

class sfdc_ProductGoldJunction__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//ProductGoldJunction__c
  public $ParentId;//ID
}

class sfdc_ProductGoldJunction__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Gold_SKU__c;//ID
  public $Gold_SKU__r;//Product2
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Product_SKU__c;//ID
  public $Product_SKU__r;//Product2
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_Product_Relation__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//Product_Relation__c
  public $ParentId;//ID
}

class sfdc_Product_Relation__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $Child__c;//ID
  public $Child__r;//Product2
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Main__c;//boolean
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $Parent__c;//ID
  public $Parent__r;//Product2
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_Profile {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $PermissionsActivateContract;//boolean
  public $PermissionsActivateOrder;//boolean
  public $PermissionsAllowEmailIC;//boolean
  public $PermissionsApiEnabled;//boolean
  public $PermissionsApiUserOnly;//boolean
  public $PermissionsAuthorApex;//boolean
  public $PermissionsBulkApiHardDelete;//boolean
  public $PermissionsCanInsertFeedSystemFields;//boolean
  public $PermissionsCanUseNewDashboardBuilder;//boolean
  public $PermissionsChatterFileLink;//boolean
  public $PermissionsChatterInternalUser;//boolean
  public $PermissionsChatterInviteExternalUsers;//boolean
  public $PermissionsChatterOwnGroups;//boolean
  public $PermissionsContentAdministrator;//boolean
  public $PermissionsConvertLeads;//boolean
  public $PermissionsCreateMultiforce;//boolean
  public $PermissionsCreateWorkspaces;//boolean
  public $PermissionsCustomizeApplication;//boolean
  public $PermissionsDataExport;//boolean
  public $PermissionsDelegatedPortalUserAdmin;//boolean
  public $PermissionsDeleteActivatedContract;//boolean
  public $PermissionsDistributeFromPersWksp;//boolean
  public $PermissionsEditActivatedOrders;//boolean
  public $PermissionsEditBrandTemplates;//boolean
  public $PermissionsEditCaseComments;//boolean
  public $PermissionsEditEvent;//boolean
  public $PermissionsEditHtmlTemplates;//boolean
  public $PermissionsEditOppLineItemUnitPrice;//boolean
  public $PermissionsEditOwnQuota;//boolean
  public $PermissionsEditPublicDocuments;//boolean
  public $PermissionsEditPublicTemplates;//boolean
  public $PermissionsEditReadonlyFields;//boolean
  public $PermissionsEditReports;//boolean
  public $PermissionsEditTask;//boolean
  public $PermissionsEmailAdministration;//boolean
  public $PermissionsEmailMass;//boolean
  public $PermissionsEmailSingle;//boolean
  public $PermissionsEmailTemplateManagement;//boolean
  public $PermissionsEnableNotifications;//boolean
  public $PermissionsExportReport;//boolean
  public $PermissionsFlowUFLRequired;//boolean
  public $PermissionsIPRestrictRequests;//boolean
  public $PermissionsImportLeads;//boolean
  public $PermissionsImportPersonal;//boolean
  public $PermissionsInboundMigrationToolsUser;//boolean
  public $PermissionsInstallMultiforce;//boolean
  public $PermissionsManageAnalyticSnapshots;//boolean
  public $PermissionsManageAuthProviders;//boolean
  public $PermissionsManageBusinessHourHolidays;//boolean
  public $PermissionsManageCallCenters;//boolean
  public $PermissionsManageCases;//boolean
  public $PermissionsManageCategories;//boolean
  public $PermissionsManageChatterMessages;//boolean
  public $PermissionsManageContentPermissions;//boolean
  public $PermissionsManageContentProperties;//boolean
  public $PermissionsManageContentTypes;//boolean
  public $PermissionsManageCssUsers;//boolean
  public $PermissionsManageCustomReportTypes;//boolean
  public $PermissionsManageDashboards;//boolean
  public $PermissionsManageDataCategories;//boolean
  public $PermissionsManageDataIntegrations;//boolean
  public $PermissionsManageDynamicDashboards;//boolean
  public $PermissionsManageEmailClientConfig;//boolean
  public $PermissionsManageEntitlements;//boolean
  public $PermissionsManageInteraction;//boolean
  public $PermissionsManageLeads;//boolean
  public $PermissionsManageMobile;//boolean
  public $PermissionsManageNetworks;//boolean
  public $PermissionsManagePartners;//boolean
  public $PermissionsManageRemoteAccess;//boolean
  public $PermissionsManageSelfService;//boolean
  public $PermissionsManageSolutions;//boolean
  public $PermissionsManageUsers;//boolean
  public $PermissionsMassInlineEdit;//boolean
  public $PermissionsModerateChatter;//boolean
  public $PermissionsModifyAllData;//boolean
  public $PermissionsNewReportBuilder;//boolean
  public $PermissionsOutboundMigrationToolsUser;//boolean
  public $PermissionsOverrideForecasts;//boolean
  public $PermissionsPasswordNeverExpires;//boolean
  public $PermissionsPublishMultiforce;//boolean
  public $PermissionsResetPasswords;//boolean
  public $PermissionsRunFlow;//boolean
  public $PermissionsRunReports;//boolean
  public $PermissionsScheduleJob;//boolean
  public $PermissionsScheduleReports;//boolean
  public $PermissionsSendSitRequests;//boolean
  public $PermissionsSolutionImport;//boolean
  public $PermissionsTransferAnyCase;//boolean
  public $PermissionsTransferAnyEntity;//boolean
  public $PermissionsTransferAnyLead;//boolean
  public $PermissionsUseTeamReassignWizards;//boolean
  public $PermissionsViewAllData;//boolean
  public $PermissionsViewAllForecasts;//boolean
  public $PermissionsViewAllUsers;//boolean
  public $PermissionsViewContent;//boolean
  public $PermissionsViewDataCategories;//boolean
  public $PermissionsViewEncryptedData;//boolean
  public $PermissionsViewMyTeamsDashboards;//boolean
  public $PermissionsViewSetup;//boolean
  public $SystemModstamp;//dateTime
  public $UserLicense;//UserLicense
  public $UserLicenseId;//ID
  public $UserType;//string
  public $Users;//QueryResult
}

class sfdc_PushTopic {
  public $ApiVersion;//double
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $IsActive;//boolean
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $NotifyForFields;//string
  public $NotifyForOperations;//string
  public $Query;//string
  public $SystemModstamp;//dateTime
}

class sfdc_QuantityForecast {
  public $Closed;//double
  public $Commit;//double
  public $CommitComment;//string
  public $CommitOverride;//double
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $DefaultRollupCommit;//double
  public $DefaultRollupUpside;//double
  public $InvalidationDate;//dateTime
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $ManagerChoiceCommit;//string
  public $ManagerChoiceUpside;//string
  public $ManagerClosed;//double
  public $ManagerCommit;//double
  public $ManagerCommitOverride;//double
  public $ManagerDefaultRollupCommit;//double
  public $ManagerDefaultRollupUpside;//double
  public $ManagerId;//ID
  public $ManagerOpportunityRollupCommit;//double
  public $ManagerOpportunityRollupUpside;//double
  public $ManagerPipeline;//double
  public $ManagerUpside;//double
  public $ManagerUpsideOverride;//double
  public $OpportunityRollupClosed;//double
  public $OpportunityRollupCommit;//double
  public $OpportunityRollupPipeline;//double
  public $OpportunityRollupUpside;//double
  public $Owner;//User
  public $OwnerId;//ID
  public $PeriodId;//ID
  public $Pipeline;//double
  public $ProductFamily;//string
  public $QuantityForecastHistories;//QueryResult
  public $Quota;//double
  public $StartDate;//date
  public $SystemModstamp;//dateTime
  public $Upside;//double
  public $UpsideComment;//string
  public $UpsideOverride;//double
}

class sfdc_QuantityForecastHistory {
  public $Closed;//double
  public $Commit;//double
  public $CommitComments;//string
  public $CommitOverridden;//boolean
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $ForecastOverride;//QuantityForecast
  public $ForecastOverrideId;//ID
  public $Pipeline;//double
  public $Quota;//double
  public $SystemModstamp;//dateTime
  public $Upside;//double
  public $UpsideComments;//string
  public $UpsideOverridden;//boolean
}

class sfdc_QueueSobject {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $Queue;//Group
  public $QueueId;//ID
  public $SobjectType;//string
  public $SystemModstamp;//dateTime
}

class sfdc_Quote {
  public $ActivityHistories;//QueryResult
  public $AdditionalCity;//string
  public $AdditionalCountry;//string
  public $AdditionalLatitude;//double
  public $AdditionalLongitude;//double
  public $AdditionalName;//string
  public $AdditionalPostalCode;//string
  public $AdditionalState;//string
  public $AdditionalStreet;//string
  public $Attachments;//QueryResult
  public $BillingCity;//string
  public $BillingCountry;//string
  public $BillingLatitude;//double
  public $BillingLongitude;//double
  public $BillingName;//string
  public $BillingPostalCode;//string
  public $BillingState;//string
  public $BillingStreet;//string
  public $Billing_City__c;//string
  public $Billing_Postal_Code__c;//string
  public $Billing_State__c;//string
  public $Billing_Street__c;//string
  public $Contact;//Contact
  public $ContactId;//ID
  public $Contact_Mailing_City__c;//string
  public $Contact_Mailing_Country__c;//string
  public $Contact_Mailing_Postal_Code__c;//string
  public $Contact_Mailing_State__c;//string
  public $Contact_Mailing_Street__c;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $CurrencyName__c;//string
  public $Currency_Text_Belgium_EN__c;//string
  public $Currency_Text_Belgium_FR__c;//string
  public $Currency_Text_Belgium_NL__c;//string
  public $Currency_Text_FR__c;//string
  public $Currency_Text_Italy__c;//string
  public $Currency_Text_NL_EN__c;//string
  public $Currency_Text_NL__c;//string
  public $Currency_Text_UK__c;//string
  public $Description;//string
  public $Discount;//double
  public $Email;//string
  public $Events;//QueryResult
  public $ExpirationDate;//date
  public $Fax;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Feeds;//QueryResult
  public $Gesamtpreis__c;//double
  public $GrandTotal;//double
  public $Incident_ID__c;//string
  public $IsDeleted;//boolean
  public $IsSyncing;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $LineItemCount;//int
  public $Mehrwertsteuer__c;//double
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Opportunity;//Opportunity
  public $OpportunityId;//ID
  public $Opportunity_ID__c;//string
  public $Opportunity_Owner_Email__c;//string
  public $Opportunity_Owner_Phone__c;//string
  public $Orders;//QueryResult
  public $Phone;//string
  public $Pricebook2;//Pricebook2
  public $Pricebook2Id;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $QuoteDocuments;//QueryResult
  public $QuoteLineItems;//QueryResult
  public $QuoteNumber;//string
  public $QuoteToCity;//string
  public $QuoteToCountry;//string
  public $QuoteToLatitude;//double
  public $QuoteToLongitude;//double
  public $QuoteToName;//string
  public $QuoteToPostalCode;//string
  public $QuoteToState;//string
  public $QuoteToStreet;//string
  public $Quote_Contact__c;//string
  public $S_Docs_Relationships__r;//QueryResult
  public $ShippingCity;//string
  public $ShippingCountry;//string
  public $ShippingHandling;//double
  public $ShippingLatitude;//double
  public $ShippingLongitude;//double
  public $ShippingName;//string
  public $ShippingPostalCode;//string
  public $ShippingState;//string
  public $ShippingStreet;//string
  public $Status;//string
  public $Subtotal;//double
  public $SystemModstamp;//dateTime
  public $TOTAL_TTC__c;//double
  public $TVA_20__c;//double
  public $Tasks;//QueryResult
  public $Tax;//double
  public $Today__c;//date
  public $TotalPrice;//double
  public $Total_Quote_Amount__c;//double
}

class sfdc_QuoteDocument {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Discount;//double
  public $Document;//base64Binary
  public $GrandTotal;//double
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Quote;//Quote
  public $QuoteId;//ID
  public $SystemModstamp;//dateTime
}

class sfdc_QuoteFeed {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//Quote
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_QuoteLineItem {
  public $Asset__c;//ID
  public $Asset__r;//Asset
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Custom_Product__c;//ID
  public $Custom_Product__r;//Product2
  public $Description;//string
  public $Discount;//double
  public $End_Date__c;//date
  public $Incident_ID__c;//string
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $LineNumber;//string
  public $ListPrice;//double
  public $OrderItems;//QueryResult
  public $Part_Number__c;//double
  public $PricebookEntry;//PricebookEntry
  public $PricebookEntryId;//ID
  public $Product_Description__c;//string
  public $Quantity;//double
  public $Quote;//Quote
  public $QuoteId;//ID
  public $Serial_Number__c;//string
  public $ServiceDate;//date
  public $SortOrder;//int
  public $Start_Date__c;//date
  public $Subtotal;//double
  public $SystemModstamp;//dateTime
  public $TotalPrice;//double
  public $UnitPrice;//double
}

class sfdc_QuoteTemplateRichTextData {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Data;//string
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $SystemModstamp;//dateTime
}

class sfdc_RecordType {
  public $BusinessProcessId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $DeveloperName;//string
  public $IsActive;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $NamespacePrefix;//string
  public $SobjectType;//string
  public $SystemModstamp;//dateTime
}

class sfdc_Ref_Country_to_Sales_Region__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//Ref_Country_to_Sales_Region__c
  public $ParentId;//ID
}

class sfdc_Ref_Country_to_Sales_Region__c {
  public $Accounts__r;//QueryResult
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $Country__c;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Leads__r;//QueryResult
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Sales_Region__c;//ID
  public $Sales_Region__r;//Sales_Region__c
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_Report {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $DeveloperName;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Feeds;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $LastRunDate;//dateTime
  public $Name;//string
  public $NamespacePrefix;//string
  public $OwnerId;//ID
  public $SystemModstamp;//dateTime
}

class sfdc_ReportFeed {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//Report
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_RevenueForecast {
  public $Closed;//double
  public $Commit;//double
  public $CommitComment;//string
  public $CommitOverride;//double
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $DefaultRollupCommit;//double
  public $DefaultRollupUpside;//double
  public $InvalidationDate;//dateTime
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $ManagerChoiceCommit;//string
  public $ManagerChoiceUpside;//string
  public $ManagerClosed;//double
  public $ManagerCommit;//double
  public $ManagerCommitOverride;//double
  public $ManagerDefaultRollupCommit;//double
  public $ManagerDefaultRollupUpside;//double
  public $ManagerId;//ID
  public $ManagerOpportunityRollupCommit;//double
  public $ManagerOpportunityRollupUpside;//double
  public $ManagerPipeline;//double
  public $ManagerUpside;//double
  public $ManagerUpsideOverride;//double
  public $OpportunityRollupClosed;//double
  public $OpportunityRollupCommit;//double
  public $OpportunityRollupPipeline;//double
  public $OpportunityRollupUpside;//double
  public $Owner;//User
  public $OwnerId;//ID
  public $PeriodId;//ID
  public $Pipeline;//double
  public $ProductFamily;//string
  public $Quota;//double
  public $RevenueForecastHistories;//QueryResult
  public $StartDate;//date
  public $SystemModstamp;//dateTime
  public $Upside;//double
  public $UpsideComment;//string
  public $UpsideOverride;//double
}

class sfdc_RevenueForecastHistory {
  public $Closed;//double
  public $Commit;//double
  public $CommitComments;//string
  public $CommitOverridden;//boolean
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $ForecastOverride;//RevenueForecast
  public $ForecastOverrideId;//ID
  public $Pipeline;//double
  public $Quota;//double
  public $SystemModstamp;//dateTime
  public $Upside;//double
  public $UpsideComments;//string
  public $UpsideOverridden;//boolean
}

class sfdc_SDOC__SDField__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SDOC__CurrencyValue__c;//double
  public $SDOC__DateTimeValue__c;//dateTime
  public $SDOC__DateValue__c;//date
  public $SDOC__EmailValue__c;//string
  public $SDOC__FieldName__c;//string
  public $SDOC__FieldType__c;//string
  public $SDOC__NumberValue__c;//double
  public $SDOC__PhoneValue__c;//string
  public $SDOC__SDoc__c;//ID
  public $SDOC__SDoc__r;//SDOC__SDoc__c
  public $SDOC__TextValue__c;//string
  public $SystemModstamp;//dateTime
}

class sfdc_SDOC__SDRelationship__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Quote__c;//ID
  public $Quote__r;//Quote
  public $SDOC__Account__c;//ID
  public $SDOC__Account__r;//Account
  public $SDOC__Asset__c;//ID
  public $SDOC__Asset__r;//Asset
  public $SDOC__Case__c;//ID
  public $SDOC__Case__r;//Case
  public $SDOC__Contact__c;//ID
  public $SDOC__Contact__r;//Contact
  public $SDOC__Contract__c;//ID
  public $SDOC__Contract__r;//Contract
  public $SDOC__Created__c;//string
  public $SDOC__Document_Comment__c;//string
  public $SDOC__Document_Created_On__c;//dateTime
  public $SDOC__Document_Name__c;//string
  public $SDOC__Document_Number__c;//string
  public $SDOC__Document_Status__c;//string
  public $SDOC__Document_Type__c;//string
  public $SDOC__Email_Link__c;//string
  public $SDOC__Lead__c;//ID
  public $SDOC__Lead__r;//Lead
  public $SDOC__Opportunity__c;//ID
  public $SDOC__Opportunity__r;//Opportunity
  public $SDOC__Product__c;//ID
  public $SDOC__Product__r;//Product2
  public $SDOC__SDoc_Rel_Comment__c;//string
  public $SDOC__SDoc_Rel_GD_Link__c;//string
  public $SDOC__SDoc_Rel_GD_Status__c;//string
  public $SDOC__SDoc_Rel_Status__c;//string
  public $SDOC__SDoc__c;//ID
  public $SDOC__SDoc__r;//SDOC__SDoc__c
  public $SDOC__Solution__c;//ID
  public $SDOC__Solution__r;//Solution
  public $SDOC__View_Link__c;//string
  public $SystemModstamp;//dateTime
}

class sfdc_SDOC__SDTemplate__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//SDOC__SDTemplate__c
  public $ParentId;//ID
}

class sfdc_SDOC__SDTemplate__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SDOC__Active__c;//boolean
  public $SDOC__Base_Object__c;//string
  public $SDOC__Base_Related_Object__c;//string
  public $SDOC__ContactRole__c;//string
  public $SDOC__Create_Attachment__c;//boolean
  public $SDOC__Default__c;//boolean
  public $SDOC__Description__c;//string
  public $SDOC__Document_Category__c;//string
  public $SDOC__Email_From_OrgWideAddressId__c;//string
  public $SDOC__Email_Lock_Body__c;//boolean
  public $SDOC__Email_Lock_SendTo__c;//boolean
  public $SDOC__Email_Lock_Subject__c;//boolean
  public $SDOC__Email_Lock_bcc__c;//boolean
  public $SDOC__Email_Lock_cc__c;//boolean
  public $SDOC__Email_ReturnToRecord__c;//boolean
  public $SDOC__Email_SendTo__c;//string
  public $SDOC__Email_Subject__c;//string
  public $SDOC__Email_bcc__c;//string
  public $SDOC__Email_cc__c;//string
  public $SDOC__Enable_Detail_Reports__c;//boolean
  public $SDOC__Format_Icon__c;//string
  public $SDOC__GD_Enabled__c;//boolean
  public $SDOC__MS_Embed_Images__c;//boolean
  public $SDOC__MS_FPFooter_BackGrndImgStyle__c;//string
  public $SDOC__MS_FPFooter_BackGrndImgUrl__c;//string
  public $SDOC__MS_FPFooter_Content__c;//string
  public $SDOC__MS_FPHeader_BackGrndImgStyle__c;//string
  public $SDOC__MS_FPHeader_BackGrndImgUrl__c;//string
  public $SDOC__MS_FPHeader_Content__c;//string
  public $SDOC__MS_Header_And_Footer_Definitions__c;//string
  public $SDOC__MS_Page_Definition__c;//string
  public $SDOC__MS_Page_Footer_Margin__c;//string
  public $SDOC__MS_Page_Header_Margin__c;//string
  public $SDOC__MS_Page_Height__c;//string
  public $SDOC__MS_Page_Margin_Left__c;//string
  public $SDOC__MS_Page_Margin_Right__c;//string
  public $SDOC__MS_Page_Width__c;//string
  public $SDOC__MS_SPFooter_BackGrndImgStyle__c;//string
  public $SDOC__MS_SPFooter_BackGrndImgUrl__c;//string
  public $SDOC__MS_SPFooter_Content__c;//string
  public $SDOC__MS_SPHeader_BackGrndImgStyle__c;//string
  public $SDOC__MS_SPHeader_BackGrndImgUrl__c;//string
  public $SDOC__MS_SPHeader_Content__c;//string
  public $SDOC__MS_Unit_of_Measure__c;//string
  public $SDOC__MS_Use_Advanced_Properties__c;//boolean
  public $SDOC__PDF_Unicode__c;//boolean
  public $SDOC__SD_K__c;//string
  public $SDOC__SDocs__r;//QueryResult
  public $SDOC__Tags__c;//string
  public $SDOC__Template_CSS_XML__c;//string
  public $SDOC__Template_Format__c;//string
  public $SDOC__Template_XML10__c;//string
  public $SDOC__Template_XML2__c;//string
  public $SDOC__Template_XML3__c;//string
  public $SDOC__Template_XML4__c;//string
  public $SDOC__Template_XML5__c;//string
  public $SDOC__Template_XML6__c;//string
  public $SDOC__Template_XML7__c;//string
  public $SDOC__Template_XML8__c;//string
  public $SDOC__Template_XML9__c;//string
  public $SDOC__Template_XML_Encode10__c;//string
  public $SDOC__Template_XML_Encode2__c;//string
  public $SDOC__Template_XML_Encode3__c;//string
  public $SDOC__Template_XML_Encode4__c;//string
  public $SDOC__Template_XML_Encode5__c;//string
  public $SDOC__Template_XML_Encode6__c;//string
  public $SDOC__Template_XML_Encode7__c;//string
  public $SDOC__Template_XML_Encode8__c;//string
  public $SDOC__Template_XML_Encode9__c;//string
  public $SDOC__Template_XML_Encode__c;//string
  public $SDOC__Template_XML__c;//string
  public $SDOC__Terms_XML_Encode__c;//string
  public $SDOC__Terms_XML__c;//string
  public $SDOC__Version__c;//string
  public $SystemModstamp;//dateTime
}

class sfdc_SDOC__SDoc__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//SDOC__SDoc__c
  public $ParentId;//ID
}

class sfdc_SDOC__SDoc__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SDOC__Attachment_ID__c;//string
  public $SDOC__Comment__c;//string
  public $SDOC__Document_Name__c;//string
  public $SDOC__Document_Number__c;//string
  public $SDOC__Document_Type__c;//string
  public $SDOC__Email_Link__c;//string
  public $SDOC__GD_Link__c;//string
  public $SDOC__GD_Status__c;//string
  public $SDOC__GD_Upload_By__c;//ID
  public $SDOC__GD_Upload_By__r;//User
  public $SDOC__LineItemData2XML__c;//string
  public $SDOC__LineItemDataXML__c;//string
  public $SDOC__ObjectID__c;//string
  public $SDOC__ObjectType__c;//string
  public $SDOC__RecordData2XML__c;//string
  public $SDOC__RecordDataXML__c;//string
  public $SDOC__RelationshipCount__c;//double
  public $SDOC__SDTemplate__c;//ID
  public $SDOC__SDTemplate__r;//SDOC__SDTemplate__c
  public $SDOC__SDocFields__r;//QueryResult
  public $SDOC__SDoc__r;//QueryResult
  public $SDOC__Status__c;//string
  public $SDOC__Version__c;//string
  public $SDOC__View_Link__c;//string
  public $SystemModstamp;//dateTime
}

class sfdc_Sales_Coach_Activity__c {
  public $Activity_Details__c;//string
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Ordering_Number__c;//double
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Sales_Coach_Stage__c;//ID
  public $Sales_Coach_Stage__r;//Sales_Coach_Stage__c
  public $SystemModstamp;//dateTime
}

class sfdc_Sales_Coach_Admin__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Stage_Title__c;//string
  public $SystemModstamp;//dateTime
}

class sfdc_Sales_Coach_Role__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//Sales_Coach_Role__c
  public $ParentId;//ID
}

class sfdc_Sales_Coach_Role__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_Sales_Coach_Section_Item__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//Sales_Coach_Section_Item__c
  public $ParentId;//ID
}

class sfdc_Sales_Coach_Section_Item__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Display__c;//boolean
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $Item_Name__c;//string
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Link_to_Content__c;//string
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Products__c;//string
  public $Sales_Coach_Section__c;//ID
  public $Sales_Coach_Section__r;//Sales_Coach_Section__c
  public $Section_Ordering__c;//double
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_Sales_Coach_Section__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//Sales_Coach_Section__c
  public $ParentId;//ID
}

class sfdc_Sales_Coach_Section__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Sales_Coach_Section_Items__r;//QueryResult
  public $Sales_Coach_Stage__c;//ID
  public $Sales_Coach_Stage__r;//Sales_Coach_Stage__c
  public $Section_Name__c;//string
  public $Section_Ordering__c;//double
  public $Section_Width__c;//double
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_Sales_Coach_Stage__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//Sales_Coach_Stage__c
  public $ParentId;//ID
}

class sfdc_Sales_Coach_Stage__c {
  public $Active__c;//boolean
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $Buyer_Stage__c;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Sales_Coach_Activities__r;//QueryResult
  public $Sales_Coach_Sections__r;//QueryResult
  public $Stage_Color__c;//string
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_Sales_Region__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//Sales_Region__c
  public $ParentId;//ID
}

class sfdc_Sales_Region__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Ref_Country_to_Sales_Region__r;//QueryResult
  public $Sales_Region__c;//string
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
}

class sfdc_Scontrol {
  public $Binary;//base64Binary
  public $BodyLength;//int
  public $ContentSource;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $DeveloperName;//string
  public $EncodingKey;//string
  public $Filename;//string
  public $HtmlWrapper;//string
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $NamespacePrefix;//string
  public $SupportsCaching;//boolean
  public $SystemModstamp;//dateTime
}

class sfdc_SelfServiceUser {
  public $ContactId;//ID
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Email;//string
  public $FirstName;//string
  public $IsActive;//boolean
  public $LanguageLocaleKey;//string
  public $LastLoginDate;//dateTime
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $LastName;//string
  public $LocaleSidKey;//string
  public $Name;//string
  public $SuperUser;//boolean
  public $SystemModstamp;//dateTime
  public $TimeZoneSidKey;//string
  public $Username;//string
}

class sfdc_ServiceContract {
  public $Account;//Account
  public $AccountId;//ID
  public $ActivationDate;//dateTime
  public $ActivityHistories;//QueryResult
  public $ApprovalStatus;//string
  public $Attachments;//QueryResult
  public $BillingCity;//string
  public $BillingCountry;//string
  public $BillingLatitude;//double
  public $BillingLongitude;//double
  public $BillingPostalCode;//string
  public $BillingState;//string
  public $BillingStreet;//string
  public $Contact;//Contact
  public $ContactId;//ID
  public $Contact_Email__c;//string
  public $Contact_Name_Language__c;//string
  public $Contact_Name_Mailing_Address__c;//string
  public $Contact_Name_Mailing_City__c;//string
  public $Contact_Name_Mailing_Country__c;//string
  public $Contact_Name_Mailing_State_Province__c;//string
  public $Contact_Name_Phone__c;//string
  public $Contact_Name__c;//string
  public $ContractLineItems;//QueryResult
  public $ContractNumber;//string
  public $Contract_Name__c;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Days_to_Expiry__c;//double
  public $Description;//string
  public $Discount;//double
  public $Distributor_Address__c;//string
  public $Distributor_Contact_Full_Name__c;//string
  public $Distributor_Contact_Language_Preferenc__c;//string
  public $Distributor_Contact_Mailing_City__c;//string
  public $Distributor_Contact_Mailing_Country__c;//string
  public $Distributor_Contact_Mailing_State_Prov__c;//string
  public $Distributor_Contact__c;//ID
  public $Distributor_Contact__r;//Contact
  public $Distributor_Email__c;//string
  public $Distributor_Phone__c;//string
  public $EndDate;//date
  public $Entitlements;//QueryResult
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Feeds;//QueryResult
  public $Gold_Model_Product_Name_Model_Group__c;//string
  public $Gold_Model_Product_Name_Product_Fam__c;//string
  public $Gold_Model_Product_Name_Standard_Pr__c;//string
  public $Gold_Model__c;//ID
  public $Gold_Model__r;//Product2
  public $Gold_Product_Family__c;//string
  public $Gold_Product_Name__c;//string
  public $GrandTotal;//double
  public $Histories;//QueryResult
  public $Incident_ID__c;//string
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $LineItemCount;//int
  public $Migrated_Distributor_Email__c;//string
  public $Migrated_Onyx_Contract_serial__c;//string
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $Pricebook2;//Pricebook2
  public $Pricebook2Id;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Purchase_Date__c;//date
  public $Purchase_Order__c;//string
  public $Sales_Order__c;//string
  public $ServiceContractHistory_Custom__r;//QueryResult
  public $ShippingCity;//string
  public $ShippingCountry;//string
  public $ShippingHandling;//double
  public $ShippingLatitude;//double
  public $ShippingLongitude;//double
  public $ShippingPostalCode;//string
  public $ShippingState;//string
  public $ShippingStreet;//string
  public $SpecialTerms;//string
  public $StartDate;//date
  public $Status;//string
  public $Subtotal;//double
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
  public $Tax;//double
  public $Term;//int
  public $TotalPrice;//double
}

class sfdc_ServiceContractFeed {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//ServiceContract
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_ServiceContractHistory {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $ServiceContract;//ServiceContract
  public $ServiceContractId;//ID
}

class sfdc_ServiceContractHistory_Custom__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//ServiceContractHistory_Custom__c
  public $ParentId;//ID
}

class sfdc_ServiceContractHistory_Custom__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Date__c;//dateTime
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Field__c;//string
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $New_Value__c;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Old_Value__c;//string
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Service_Contract__c;//ID
  public $Service_Contract__r;//ServiceContract
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
  public $User__c;//ID
  public $User__r;//User
}

class sfdc_ServiceContractShare {
  public $AccessLevel;//string
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Parent;//ServiceContract
  public $ParentId;//ID
  public $RowCause;//string
  public $UserOrGroupId;//ID
}

class sfdc_SetupEntityAccess {
  public $Parent;//PermissionSet
  public $ParentId;//ID
  public $SetupEntityId;//ID
  public $SetupEntityType;//string
  public $SystemModstamp;//dateTime
}

class sfdc_Site {
  public $Admin;//User
  public $AdminId;//ID
  public $AnalyticsTrackingCode;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $DailyBandwidthLimit;//int
  public $DailyBandwidthUsed;//int
  public $DailyRequestTimeLimit;//int
  public $DailyRequestTimeUsed;//int
  public $Description;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Feeds;//QueryResult
  public $Histories;//QueryResult
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $MasterLabel;//string
  public $MonthlyPageViewsEntitlement;//int
  public $Name;//string
  public $OptionsAllowHomePage;//boolean
  public $OptionsAllowStandardAnswersPages;//boolean
  public $OptionsAllowStandardIdeasPages;//boolean
  public $OptionsAllowStandardLookups;//boolean
  public $OptionsAllowStandardSearch;//boolean
  public $OptionsEnableFeeds;//boolean
  public $SiteDomainPaths;//QueryResult
  public $SiteType;//string
  public $Status;//string
  public $Subdomain;//string
  public $SystemModstamp;//dateTime
  public $UrlPathPrefix;//string
}

class sfdc_SiteFeed {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//Site
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_SiteHistory {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Site;//Site
  public $SiteId;//ID
}

class sfdc_SlaProcess {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $IsActive;//boolean
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $StartDateField;//string
  public $SystemModstamp;//dateTime
}

class sfdc_Solution {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $CaseSolutions;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Feeds;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $IsHtml;//boolean
  public $IsPublished;//boolean
  public $IsPublishedInPublicKb;//boolean
  public $IsReviewed;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $OpenActivities;//QueryResult
  public $Owner;//User
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SDOC__SDoc_Relationships__r;//QueryResult
  public $SolutionName;//string
  public $SolutionNote;//string
  public $SolutionNumber;//string
  public $Status;//string
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
  public $TimesUsed;//int
  public $Votes;//QueryResult
}

class sfdc_SolutionFeed {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//Solution
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_SolutionHistory {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Solution;//Solution
  public $SolutionId;//ID
}

class sfdc_SolutionStatus {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDefault;//boolean
  public $IsReviewed;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $MasterLabel;//string
  public $SortOrder;//int
  public $SystemModstamp;//dateTime
}

class sfdc_StaticResource {
  public $Body;//base64Binary
  public $BodyLength;//int
  public $CacheControl;//string
  public $ContentType;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $NamespacePrefix;//string
  public $SystemModstamp;//dateTime
}

class sfdc_Task {
  public $Account;//Account
  public $AccountId;//ID
  public $ActivityDate;//date
  public $ActivityId__c;//string
  public $Activity_Result__c;//string
  public $Attachments;//QueryResult
  public $CallDisposition;//string
  public $CallDurationInSeconds;//int
  public $CallObject;//string
  public $CallType;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Delta_in_minutes__c;//double
  public $Description;//string
  public $EVAL_Model__c;//string
  public $EVAL_Order_Status__c;//string
  public $EVAL_Purchase_Date__c;//date
  public $EVAL_Return_Date__c;//date
  public $EVAL_Serial_Number__c;//string
  public $EVAL_Ship_Date__c;//date
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Feeds;//QueryResult
  public $IsArchived;//boolean
  public $IsClosed;//boolean
  public $IsDeleted;//boolean
  public $IsRecurrence;//boolean
  public $IsReminderSet;//boolean
  public $IsVisibleInSelfService;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Owner;//Name
  public $OwnerId;//ID
  public $Priority;//string
  public $RecurrenceActivityId;//ID
  public $RecurrenceDayOfMonth;//int
  public $RecurrenceDayOfWeekMask;//int
  public $RecurrenceEndDateOnly;//date
  public $RecurrenceInstance;//string
  public $RecurrenceInterval;//int
  public $RecurrenceMonthOfYear;//string
  public $RecurrenceStartDateOnly;//date
  public $RecurrenceTimeZoneSidKey;//string
  public $RecurrenceType;//string
  public $RecurringTasks;//QueryResult
  public $ReminderDateTime;//dateTime
  public $Status;//string
  public $Subject;//string
  public $SystemModstamp;//dateTime
  public $Type;//string
  public $What;//Name
  public $WhatId;//ID
  public $Who;//Name
  public $WhoId;//ID
  public $qbdialer__CallRecordingURL__c;//string
  public $qbdialer__Call_Date_Time__c;//dateTime
  public $qbdialer__Call_Dial_Number__c;//double
  public $qbdialer__Call_Hour__c;//string
  public $qbdialer__Call_Lead_Status__c;//string
  public $qbdialer__Call_Ring_Time__c;//double
  public $qbdialer__Call_Time_Zone__c;//string
  public $qbdialer__Callback_Date_Time__c;//dateTime
  public $qbdialer__ImpressionId__c;//double
  public $qbdialer__SMSReminder__c;//boolean
}

class sfdc_TaskAssignment__c {
  public $Attachments;//QueryResult
  public $Country__c;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $PostCodeEnd__c;//string
  public $PostCode__c;//string
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $ProductFamily__c;//string
  public $Queue_Name__c;//string
  public $Region__c;//string
  public $SystemModstamp;//dateTime
  public $UserName__c;//ID
  public $UserName__r;//User
}

class sfdc_TaskFeed {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//Task
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_TaskPriority {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDefault;//boolean
  public $IsHighPriority;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $MasterLabel;//string
  public $SortOrder;//int
  public $SystemModstamp;//dateTime
}

class sfdc_TaskRecurrenceException {
  public $ActivityDateOriginal;//dateTime
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDeletion;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $RecurrenceTaskId;//ID
  public $SystemModstamp;//dateTime
  public $TaskId;//ID
}

class sfdc_TaskStatus {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsClosed;//boolean
  public $IsDefault;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $MasterLabel;//string
  public $SortOrder;//int
  public $SystemModstamp;//dateTime
}

class sfdc_Topic {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Name;//string
  public $SystemModstamp;//dateTime
}

class sfdc_User {
  public $AboutMe;//string
  public $AccountId;//ID
  public $Alias;//string
  public $AssetHistories__r;//QueryResult
  public $CallCenterId;//ID
  public $Cases__r;//QueryResult
  public $City;//string
  public $CommunityNickname;//string
  public $CompanyName;//string
  public $Contact;//Contact
  public $ContactId;//ID
  public $ContractsSigned;//QueryResult
  public $Country;//string
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $DefaultCurrencyIsoCode;//string
  public $DefaultGroupNotificationFrequency;//string
  public $DelegatedApproverId;//ID
  public $DelegatedUsers;//QueryResult
  public $Department;//string
  public $DigestFrequency;//string
  public $Division;//string
  public $Email;//string
  public $EmailEncodingKey;//string
  public $EmployeeNumber;//string
  public $EventRelations;//QueryResult
  public $Extension;//string
  public $ExternalDataUserAuths;//QueryResult
  public $Fax;//string
  public $FederationIdentifier;//string
  public $FeedSubscriptions;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Feeds;//QueryResult
  public $FirstName;//string
  public $ForecastEnabled;//boolean
  public $FullPhotoUrl;//string
  public $GroupMemberships;//QueryResult
  public $IsActive;//boolean
  public $IsPortalEnabled;//boolean
  public $IsPrmSuperUser;//boolean
  public $LanguageLocaleKey;//string
  public $LastLoginDate;//dateTime
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $LastName;//string
  public $LastPasswordChangeDate;//dateTime
  public $Latitude;//double
  public $Leads__r;//QueryResult
  public $LocaleSidKey;//string
  public $Longitude;//double
  public $ManagedUsers;//QueryResult
  public $Manager;//User
  public $ManagerId;//ID
  public $MobilePhone;//string
  public $Name;//string
  public $OfflinePdaTrialExpirationDate;//dateTime
  public $OfflineTrialExpirationDate;//dateTime
  public $Opportunities1__r;//QueryResult
  public $Opportunities2__r;//QueryResult
  public $Opportunities3__r;//QueryResult
  public $Opportunities_History__r;//QueryResult
  public $Opportunities__r;//QueryResult
  public $OpportunityTeams;//QueryResult
  public $PermissionSetAssignments;//QueryResult
  public $Phone;//string
  public $PostalCode;//string
  public $Profile;//Profile
  public $ProfileId;//ID
  public $Quote_prepared_by__c;//string
  public $ReceivesAdminInfoEmails;//boolean
  public $ReceivesInfoEmails;//boolean
  public $SDOC__S_Docs__r;//QueryResult
  public $ServiceContractHistory_Custom__r;//QueryResult
  public $Shares;//QueryResult
  public $SmallPhotoUrl;//string
  public $State;//string
  public $Street;//string
  public $SystemModstamp;//dateTime
  public $TaskAssignments__r;//QueryResult
  public $TimeZoneSidKey;//string
  public $Title;//string
  public $URL__c;//string
  public $UserPermissionsAvantgoUser;//boolean
  public $UserPermissionsCallCenterAutoLogin;//boolean
  public $UserPermissionsChatterAnswersUser;//boolean
  public $UserPermissionsInteractionUser;//boolean
  public $UserPermissionsMarketingUser;//boolean
  public $UserPermissionsMobileUser;//boolean
  public $UserPermissionsOfflineUser;//boolean
  public $UserPermissionsSFContentUser;//boolean
  public $UserPermissionsSupportUser;//boolean
  public $UserPreferences;//QueryResult
  public $UserPreferencesActivityRemindersPopup;//boolean
  public $UserPreferencesApexPagesDeveloperMode;//boolean
  public $UserPreferencesDisCommentAfterLikeEmail;//boolean
  public $UserPreferencesDisMentionsCommentEmail;//boolean
  public $UserPreferencesDisProfPostCommentEmail;//boolean
  public $UserPreferencesDisableAllFeedsEmail;//boolean
  public $UserPreferencesDisableBookmarkEmail;//boolean
  public $UserPreferencesDisableChangeCommentEmail;//boolean
  public $UserPreferencesDisableFileShareNotificationsForApi;//boolean
  public $UserPreferencesDisableFollowersEmail;//boolean
  public $UserPreferencesDisableLaterCommentEmail;//boolean
  public $UserPreferencesDisableLikeEmail;//boolean
  public $UserPreferencesDisableMentionsPostEmail;//boolean
  public $UserPreferencesDisableMessageEmail;//boolean
  public $UserPreferencesDisableProfilePostEmail;//boolean
  public $UserPreferencesDisableSharePostEmail;//boolean
  public $UserPreferencesEnableAutoSubForFeeds;//boolean
  public $UserPreferencesEventRemindersCheckboxDefault;//boolean
  public $UserPreferencesHideCSNDesktopTask;//boolean
  public $UserPreferencesHideCSNGetChatterMobileTask;//boolean
  public $UserPreferencesOptOutOfTouch;//boolean
  public $UserPreferencesReminderSoundOff;//boolean
  public $UserPreferencesShowCityToExternalUsers;//boolean
  public $UserPreferencesShowCountryToExternalUsers;//boolean
  public $UserPreferencesShowEmailToExternalUsers;//boolean
  public $UserPreferencesShowFaxToExternalUsers;//boolean
  public $UserPreferencesShowManagerToExternalUsers;//boolean
  public $UserPreferencesShowMobilePhoneToExternalUsers;//boolean
  public $UserPreferencesShowPostalCodeToExternalUsers;//boolean
  public $UserPreferencesShowStateToExternalUsers;//boolean
  public $UserPreferencesShowStreetAddressToExternalUsers;//boolean
  public $UserPreferencesShowTitleToExternalUsers;//boolean
  public $UserPreferencesShowWorkPhoneToExternalUsers;//boolean
  public $UserPreferencesTaskRemindersCheckboxDefault;//boolean
  public $UserRole;//UserRole
  public $UserRoleId;//ID
  public $UserSites;//QueryResult
  public $UserTeams;//QueryResult
  public $UserType;//string
  public $Username;//string
  public $mkto_si__IsCachingAnonWebActivityList__c;//boolean
  public $mkto_si__IsCachingBestBets__c;//boolean
  public $mkto_si__IsCachingEmailActivityList__c;//boolean
  public $mkto_si__IsCachingGroupedWebActivityList__c;//boolean
  public $mkto_si__IsCachingInterestingMomentsList__c;//boolean
  public $mkto_si__IsCachingScoringList__c;//boolean
  public $mkto_si__IsCachingStreamList__c;//boolean
  public $mkto_si__IsCachingWatchList__c;//boolean
  public $mkto_si__IsCachingWebActivityList__c;//boolean
  public $mkto_si__Sales_Insight_Counter__c;//double
  public $qbdialer__InsideSales_Admin__c;//boolean
  public $qbdialer__is_subdomain__c;//string
  public $qbdialer__is_token__c;//string
  public $qbdialer__password__c;//string
  public $qbdialer__permissions__c;//string
  public $qbdialer__username__c;//string
}

class sfdc_UserFeed {
  public $Body;//string
  public $CommentCount;//int
  public $ContentData;//base64Binary
  public $ContentDescription;//string
  public $ContentFileName;//string
  public $ContentSize;//int
  public $ContentType;//string
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $FeedComments;//QueryResult
  public $FeedLikes;//QueryResult
  public $FeedTrackedChanges;//QueryResult
  public $InsertedBy;//Name
  public $InsertedById;//ID
  public $IsDeleted;//boolean
  public $LastModifiedDate;//dateTime
  public $LikeCount;//int
  public $LinkUrl;//string
  public $Parent;//User
  public $ParentId;//ID
  public $RelatedRecordId;//ID
  public $SystemModstamp;//dateTime
  public $Title;//string
  public $Type;//string
}

class sfdc_UserLicense {
  public $LicenseDefinitionKey;//string
  public $MonthlyLoginsEntitlement;//int
  public $MonthlyLoginsUsed;//int
  public $Name;//string
  public $SystemModstamp;//dateTime
}

class sfdc_UserPreference {
  public $Preference;//string
  public $SystemModstamp;//dateTime
  public $UserId;//ID
  public $Value;//string
}

class sfdc_UserRecordAccess {
  public $HasAllAccess;//boolean
  public $HasDeleteAccess;//boolean
  public $HasEditAccess;//boolean
  public $HasReadAccess;//boolean
  public $HasTransferAccess;//boolean
  public $MaxAccessLevel;//string
  public $RecordId;//string
  public $UserId;//ID
}

class sfdc_UserRole {
  public $CaseAccessForAccountOwner;//string
  public $ContactAccessForAccountOwner;//string
  public $DeveloperName;//string
  public $ForecastUserId;//ID
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $MayForecastManagerShare;//boolean
  public $Name;//string
  public $OpportunityAccessForAccountOwner;//string
  public $ParentRoleId;//ID
  public $PortalAccountId;//ID
  public $PortalAccountOwnerId;//ID
  public $PortalRole;//string
  public $PortalType;//string
  public $RollupDescription;//string
  public $SystemModstamp;//dateTime
  public $Users;//QueryResult
}

class sfdc_UserShare {
  public $IsActive;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $RowCause;//string
  public $User;//User
  public $UserAccessLevel;//string
  public $UserId;//ID
  public $UserOrGroupId;//ID
}

class sfdc_UserTeamMember {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $OpportunityAccessLevel;//string
  public $OwnerId;//ID
  public $SystemModstamp;//dateTime
  public $TeamMemberRole;//string
  public $User;//User
  public $UserId;//ID
}

class sfdc_Vote {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $IsDeleted;//boolean
  public $Parent;//Name
  public $ParentId;//ID
  public $SystemModstamp;//dateTime
  public $Type;//string
}

class sfdc_WebLink {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Description;//string
  public $DisplayType;//string
  public $EncodingKey;//string
  public $HasMenubar;//boolean
  public $HasScrollbars;//boolean
  public $HasToolbar;//boolean
  public $Height;//int
  public $IsProtected;//boolean
  public $IsResizable;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $LinkType;//string
  public $MasterLabel;//string
  public $Name;//string
  public $NamespacePrefix;//string
  public $OpenType;//string
  public $PageOrSobjectType;//string
  public $Position;//string
  public $RequireRowSelection;//boolean
  public $ScontrolId;//ID
  public $ShowsLocation;//boolean
  public $ShowsStatus;//boolean
  public $SystemModstamp;//dateTime
  public $Url;//string
  public $Width;//int
}

class sfdc_fnuCustomerGoldIdentifierOnyx__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//fnuCustomerGoldIdentifierOnyx__c
  public $ParentId;//ID
}

class sfdc_fnuCustomerGoldIdentifierOnyx__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $Processed__c;//boolean
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
  public $chGoldPIN__c;//string
  public $chInsertBy__c;//string
  public $chUpdateBy__c;//string
  public $dtInsertDate__c;//dateTime
  public $dtUpdateDate__c;//dateTime
  public $iOwnerId__c;//string
  public $iSiteId__c;//double
  public $siIdentifierType__c;//double
  public $tiRecordStatus__c;//double
  public $vchGoldIdentifier__c;//string
}

class sfdc_mkto_si__BestBetsCache__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $mkto_si__AccountLinkName__c;//string
  public $mkto_si__AccountLink__c;//string
  public $mkto_si__BestBetsView__c;//string
  public $mkto_si__ContactId__c;//string
  public $mkto_si__ContactLink__c;//string
  public $mkto_si__ContactName__c;//string
  public $mkto_si__Id__c;//string
  public $mkto_si__LIMDate__c;//dateTime
  public $mkto_si__LIMDesc__c;//string
  public $mkto_si__LIMType__c;//string
  public $mkto_si__LeadScore__c;//string
  public $mkto_si__Priority__c;//string
  public $mkto_si__RelativeScore__c;//string
  public $mkto_si__RowNum__c;//string
  public $mkto_si__SObjectType__c;//string
  public $mkto_si__Status__c;//string
  public $mkto_si__TotalCount__c;//string
  public $mkto_si__Urgency__c;//string
}

class sfdc_mkto_si__Best_Bets_View_Detail__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $mkto_si__Best_Bets_View__c;//ID
  public $mkto_si__Best_Bets_View__r;//mkto_si__Best_Bets_View__c
  public $mkto_si__FieldLabel__c;//string
  public $mkto_si__FieldName__c;//string
  public $mkto_si__FieldNumber__c;//double
  public $mkto_si__FieldType__c;//string
  public $mkto_si__LookupValue__c;//string
  public $mkto_si__Operator__c;//string
  public $mkto_si__ShowField__c;//boolean
  public $mkto_si__Value__c;//string
}

class sfdc_mkto_si__Best_Bets_View__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $mkto_si__Best_Bets_View_Details__r;//QueryResult
  public $mkto_si__IncludeDefaultColumns__c;//boolean
  public $mkto_si__MaxPages__c;//double
  public $mkto_si__MaxRows__c;//double
  public $mkto_si__Object__c;//string
  public $mkto_si__OwnerFilter__c;//string
  public $mkto_si__ShowRecordsWithNegativeScores__c;//boolean
}

class sfdc_mkto_si__EmailActivityCache__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $mkto_si__AccountLinkName__c;//string
  public $mkto_si__AccountLink__c;//string
  public $mkto_si__ActivityDT__c;//dateTime
  public $mkto_si__Campaign__c;//string
  public $mkto_si__ClickCount__c;//string
  public $mkto_si__ContactLinkName__c;//string
  public $mkto_si__ContactLink__c;//string
  public $mkto_si__Id__c;//string
  public $mkto_si__MessageId__c;//string
  public $mkto_si__MessageThreadIndex__c;//string
  public $mkto_si__MessageType__c;//string
  public $mkto_si__OpenCount__c;//string
  public $mkto_si__RowNum__c;//string
  public $mkto_si__Status__c;//string
  public $mkto_si__Subject__c;//string
  public $mkto_si__ThreadNumber__c;//string
  public $mkto_si__ThreadSubject__c;//string
  public $mkto_si__TotalCount__c;//string
}

class sfdc_mkto_si__GroupedWebActivityCache__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $mkto_si__AccountLinkName__c;//string
  public $mkto_si__AccountLink__c;//string
  public $mkto_si__City__c;//string
  public $mkto_si__ContactLinkName__c;//string
  public $mkto_si__ContactLink__c;//string
  public $mkto_si__Country__c;//string
  public $mkto_si__Id__c;//string
  public $mkto_si__IsAnonymous__c;//boolean
  public $mkto_si__LastVisitDT__c;//dateTime
  public $mkto_si__PageViews__c;//string
  public $mkto_si__RowNum__c;//string
  public $mkto_si__SearchLinkName__c;//string
  public $mkto_si__SearchLink__c;//string
  public $mkto_si__State__c;//string
  public $mkto_si__TotalCount__c;//string
  public $mkto_si__WPageLinkName__c;//string
  public $mkto_si__WPageLink__c;//string
}

class sfdc_mkto_si__InterestingMomentsCache__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $mkto_si__AccountLinkName__c;//string
  public $mkto_si__AccountLink__c;//string
  public $mkto_si__ActivityDT__c;//dateTime
  public $mkto_si__Campaign__c;//string
  public $mkto_si__ContactLinkName__c;//string
  public $mkto_si__ContactLink__c;//string
  public $mkto_si__Id__c;//string
  public $mkto_si__MomentNote__c;//string
  public $mkto_si__MomentType__c;//string
  public $mkto_si__RowNum__c;//string
  public $mkto_si__TotalCount__c;//string
}

class sfdc_mkto_si__MarketoSettings__c {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SetupOwner;//Name
  public $SetupOwnerId;//ID
  public $SystemModstamp;//dateTime
  public $mkto_si__BatchSize__c;//string
  public $mkto_si__CacheMinutesUntilExpired__c;//string
  public $mkto_si__CacheState__c;//boolean
  public $mkto_si__MinutesToRefreshCache__c;//string
  public $mkto_si__MinutesToRefreshLeadFeed__c;//string
  public $mkto_si__UseCache__c;//boolean
}

class sfdc_mkto_si__Marketo_Sales_Insight_Config__History {
  public $CreatedBy;//Name
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $Field;//string
  public $IsDeleted;//boolean
  public $NewValue;//anyType
  public $OldValue;//anyType
  public $Parent;//mkto_si__Marketo_Sales_Insight_Config__c
  public $ParentId;//ID
}

class sfdc_mkto_si__Marketo_Sales_Insight_Config__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $Histories;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $mkto_si__API_Secret_Key__c;//string
  public $mkto_si__API_URL__c;//string
  public $mkto_si__API_User_Id__c;//string
  public $mkto_si__Enable_Marketo_API__c;//boolean
  public $mkto_si__Enable_RSS__c;//boolean
  public $mkto_si__Marketo_Host__c;//string
  public $mkto_si__Test_Configuration__c;//string
}

class sfdc_mkto_si__ScoringCache__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $mkto_si__AccountLinkName__c;//string
  public $mkto_si__AccountLink__c;//string
  public $mkto_si__ActivityDT__c;//dateTime
  public $mkto_si__Campaign__c;//string
  public $mkto_si__ContactLinkName__c;//string
  public $mkto_si__ContactLink__c;//string
  public $mkto_si__Id__c;//string
  public $mkto_si__NewValue__c;//string
  public $mkto_si__OldValue__c;//string
  public $mkto_si__Reason__c;//string
  public $mkto_si__RowNum__c;//string
  public $mkto_si__ScoreName__c;//string
  public $mkto_si__TotalCount__c;//string
}

class sfdc_mkto_si__UserPreferences__c {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SetupOwner;//Name
  public $SetupOwnerId;//ID
  public $SystemModstamp;//dateTime
  public $mkto_si__BestBetsView__c;//string
  public $mkto_si__LastWhatIsNewVersion__c;//string
  public $mkto_si__MaxPagesAWA__c;//double
  public $mkto_si__MaxPagesIM__c;//double
  public $mkto_si__MaxPagesMBB__c;//double
  public $mkto_si__MaxPagesME__c;//double
  public $mkto_si__MaxPagesMHBB__c;//double
  public $mkto_si__MaxPagesMTBB__c;//double
  public $mkto_si__MaxPagesMWL__c;//double
  public $mkto_si__MaxPagesSC__c;//double
  public $mkto_si__MaxPagesWA__c;//double
  public $mkto_si__MaxPages__c;//double
  public $mkto_si__ShowWhatIsNew__c;//boolean
  public $mkto_si__TimeFrameDays__c;//double
}

class sfdc_mkto_si__Value__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $mkto_si__Boolean__c;//boolean
  public $mkto_si__Currency__c;//double
  public $mkto_si__DateTime__c;//dateTime
  public $mkto_si__Date__c;//date
  public $mkto_si__Double__c;//double
  public $mkto_si__Email__c;//string
  public $mkto_si__Percent__c;//double
  public $mkto_si__Phone__c;//string
  public $mkto_si__String__c;//string
  public $mkto_si__TextArea__c;//string
  public $mkto_si__Url__c;//string
  public $mkto_si__ValueType__c;//string
}

class sfdc_mkto_si__WebActivityCache__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $mkto_si__AccountLinkName__c;//string
  public $mkto_si__AccountLink__c;//string
  public $mkto_si__Account__c;//ID
  public $mkto_si__Account__r;//Account
  public $mkto_si__ActivityDT__c;//dateTime
  public $mkto_si__ContactLinkName__c;//string
  public $mkto_si__ContactLink__c;//string
  public $mkto_si__Contact__c;//ID
  public $mkto_si__Contact__r;//Contact
  public $mkto_si__Id__c;//string
  public $mkto_si__Lead__c;//ID
  public $mkto_si__Lead__r;//Lead
  public $mkto_si__Opportunity__c;//ID
  public $mkto_si__Opportunity__r;//Opportunity
  public $mkto_si__RowNum__c;//string
  public $mkto_si__SActivityDT__c;//string
  public $mkto_si__SearchLinkName__c;//string
  public $mkto_si__SearchLink__c;//string
  public $mkto_si__TotalCount__c;//string
  public $mkto_si__WPageLinkName__c;//string
  public $mkto_si__WPageLink__c;//string
}

class sfdc_qbdialer__DialerQueryAttendee__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $qbdialer__DialerQueryId__c;//ID
  public $qbdialer__DialerQueryId__r;//qbdialer__DialerQuery__c
}

class sfdc_qbdialer__DialerQueryItem__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $qbdialer__AccountId__c;//ID
  public $qbdialer__AccountId__r;//Account
  public $qbdialer__ContactId__c;//ID
  public $qbdialer__ContactId__r;//Contact
  public $qbdialer__Dialed__c;//boolean
  public $qbdialer__DialerQueryId__c;//ID
  public $qbdialer__DialerQueryId__r;//qbdialer__DialerQuery__c
  public $qbdialer__LeadId__c;//ID
  public $qbdialer__LeadId__r;//Lead
  public $qbdialer__RelatedItemId__c;//string
}

class sfdc_qbdialer__DialerQuery__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $qbdialer__AdvancedFilter__c;//string
  public $qbdialer__Attendees__c;//string
  public $qbdialer__Callback_action__c;//string
  public $qbdialer__Callback_grace_period__c;//double
  public $qbdialer__Caller_Id__c;//string
  public $qbdialer__CampaignId__c;//string
  public $qbdialer__CampaignMemberStatus__c;//string
  public $qbdialer__CaseType__c;//string
  public $qbdialer__DataSource__c;//string
  public $qbdialer__DialerInitiativeId__c;//string
  public $qbdialer__DialerQueryAttendees__r;//QueryResult
  public $qbdialer__Dialer_Query_Items__r;//QueryResult
  public $qbdialer__EightHundred__c;//boolean
  public $qbdialer__EmailFolders__c;//string
  public $qbdialer__EndTime__c;//string
  public $qbdialer__Filter_Data_10__c;//string
  public $qbdialer__Filter_Data_1__c;//string
  public $qbdialer__Filter_Data_2__c;//string
  public $qbdialer__Filter_Data_3__c;//string
  public $qbdialer__Filter_Data_4__c;//string
  public $qbdialer__Filter_Data_5__c;//string
  public $qbdialer__Filter_Data_6__c;//string
  public $qbdialer__Filter_Data_7__c;//string
  public $qbdialer__Filter_Data_8__c;//string
  public $qbdialer__Filter_Data_9__c;//string
  public $qbdialer__Filter_Field_10__c;//string
  public $qbdialer__Filter_Field_1__c;//string
  public $qbdialer__Filter_Field_2__c;//string
  public $qbdialer__Filter_Field_3__c;//string
  public $qbdialer__Filter_Field_4__c;//string
  public $qbdialer__Filter_Field_5__c;//string
  public $qbdialer__Filter_Field_6__c;//string
  public $qbdialer__Filter_Field_7__c;//string
  public $qbdialer__Filter_Field_8__c;//string
  public $qbdialer__Filter_Field_9__c;//string
  public $qbdialer__Filter_Op_10__c;//string
  public $qbdialer__Filter_Op_1__c;//string
  public $qbdialer__Filter_Op_2__c;//string
  public $qbdialer__Filter_Op_3__c;//string
  public $qbdialer__Filter_Op_4__c;//string
  public $qbdialer__Filter_Op_5__c;//string
  public $qbdialer__Filter_Op_6__c;//string
  public $qbdialer__Filter_Op_7__c;//string
  public $qbdialer__Filter_Op_8__c;//string
  public $qbdialer__Filter_Op_9__c;//string
  public $qbdialer__LimitCallingTimes__c;//boolean
  public $qbdialer__LimitCallsTo__c;//string
  public $qbdialer__LimitEndTime__c;//string
  public $qbdialer__LimitStartTime__c;//string
  public $qbdialer__Local_Presence_Bucket__c;//string
  public $qbdialer__MaxDials__c;//double
  public $qbdialer__MinDials__c;//double
  public $qbdialer__MinutesBetweenCalls__c;//double
  public $qbdialer__ObjectType__c;//string
  public $qbdialer__OnlyDialOwn__c;//boolean
  public $qbdialer__OpportunityType__c;//string
  public $qbdialer__OwnershipFilter__c;//string
  public $qbdialer__PercentComplete__c;//double
  public $qbdialer__Prevent_callbacks__c;//boolean
  public $qbdialer__Priority__c;//double
  public $qbdialer__QueueOwnership__c;//string
  public $qbdialer__ReportFolder__c;//string
  public $qbdialer__ReportIdColumn__c;//string
  public $qbdialer__ReportId__c;//string
  public $qbdialer__ReportName__c;//string
  public $qbdialer__RingTimeout__c;//double
  public $qbdialer__SeekInitiativeId__c;//ID
  public $qbdialer__SeekInitiativeId__r;//qbdialer__SeekInitiative__c
  public $qbdialer__Seek_Initiative_Items__r;//QueryResult
  public $qbdialer__SmartSort__c;//string
  public $qbdialer__Sort_Direction_1__c;//string
  public $qbdialer__Sort_Direction_2__c;//string
  public $qbdialer__Sort_Direction_3__c;//string
  public $qbdialer__Sort_Field_1__c;//string
  public $qbdialer__Sort_Field_2__c;//string
  public $qbdialer__Sort_Field_3__c;//string
  public $qbdialer__StartTime__c;//string
  public $qbdialer__Test_Local_Presence__c;//boolean
  public $qbdialer__TimeZone__c;//string
  public $qbdialer__TimeZones__c;//string
  public $qbdialer__TotalItemsDialed__c;//double
  public $qbdialer__TotalItems__c;//double
  public $qbdialer__UseSalesforceEmailTemplates__c;//boolean
  public $qbdialer__Use_Local_Presence__c;//boolean
  public $qbdialer__can_edit__c;//boolean
  public $qbdialer__datetester__c;//dateTime
}

class sfdc_qbdialer__SeekInitiativeAttendee__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $qbdialer__SeekInitiativeId__c;//ID
  public $qbdialer__SeekInitiativeId__r;//qbdialer__SeekInitiative__c
}

class sfdc_qbdialer__SeekInitiativeItem__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $qbdialer__AccountId__c;//ID
  public $qbdialer__AccountId__r;//Account
  public $qbdialer__ContactId__c;//ID
  public $qbdialer__ContactId__r;//Contact
  public $qbdialer__DialerQueryId__c;//ID
  public $qbdialer__DialerQueryId__r;//qbdialer__DialerQuery__c
  public $qbdialer__LeadId__c;//ID
  public $qbdialer__LeadId__r;//Lead
  public $qbdialer__SeekInitiativeId__c;//ID
  public $qbdialer__SeekInitiativeId__r;//qbdialer__SeekInitiative__c
  public $qbdialer__Unique__c;//string
}

class sfdc_qbdialer__SeekInitiative__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $qbdialer__Attendees__c;//string
  public $qbdialer__CallbackGracePeriod__c;//double
  public $qbdialer__CallbackPermission__c;//string
  public $qbdialer__CallerID__c;//string
  public $qbdialer__DialerInitiativeId__c;//double
  public $qbdialer__Dialer_Queries__r;//QueryResult
  public $qbdialer__EmailFolders__c;//string
  public $qbdialer__EndTime__c;//string
  public $qbdialer__LimitCallingTimes__c;//boolean
  public $qbdialer__LimitCallsTo__c;//string
  public $qbdialer__Local_Presence_Bucket__c;//string
  public $qbdialer__OnlyDialOwn__c;//boolean
  public $qbdialer__Prevent_callbacks__c;//boolean
  public $qbdialer__RingTimeout__c;//double
  public $qbdialer__Seek_Initiative_Attendees__r;//QueryResult
  public $qbdialer__Seek_Initiative_Items__r;//QueryResult
  public $qbdialer__Show_Query__c;//boolean
  public $qbdialer__SmartSort__c;//string
  public $qbdialer__StartTime__c;//string
  public $qbdialer__Test_Local_Presence__c;//boolean
  public $qbdialer__TimeBetweenCalls__c;//double
  public $qbdialer__UseSalesforceEmailTemplates__c;//boolean
  public $qbdialer__Use_Local_Presence__c;//boolean
  public $qbdialer__can_edit__c;//boolean
}

class sfdc_qbdialer__UserStatusLog__c {
  public $ActivityHistories;//QueryResult
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $Events;//QueryResult
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastActivityDate;//date
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $OpenActivities;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $Tasks;//QueryResult
  public $qbdialer__AgentStatus__c;//string
  public $qbdialer__InsideSalesId__c;//double
  public $qbdialer__StatusDate__c;//date
  public $qbdialer__StatusDuration__c;//double
}

class sfdc_qbdialer__isDialerConfig__c {
  public $Attachments;//QueryResult
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $Notes;//QueryResult
  public $NotesAndAttachments;//QueryResult
  public $Owner;//Name
  public $OwnerId;//ID
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SystemModstamp;//dateTime
  public $qbdialer__Config__c;//string
  public $qbdialer__InsideSalesHost__c;//string
}

class sfdc_quotesync__QuoteLineSyncField__c {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SetupOwner;//Name
  public $SetupOwnerId;//ID
  public $SystemModstamp;//dateTime
  public $quotesync__OppLineSyncField__c;//string
}

class sfdc_quotesync__QuoteSyncField__c {
  public $CreatedBy;//User
  public $CreatedById;//ID
  public $CreatedDate;//dateTime
  public $CurrencyIsoCode;//string
  public $FeedSubscriptionsForEntity;//QueryResult
  public $IsDeleted;//boolean
  public $LastModifiedBy;//User
  public $LastModifiedById;//ID
  public $LastModifiedDate;//dateTime
  public $Name;//string
  public $ProcessInstances;//QueryResult
  public $ProcessSteps;//QueryResult
  public $SetupOwner;//Name
  public $SetupOwnerId;//ID
  public $SystemModstamp;//dateTime
  public $quotesync__OppSyncField__c;//string
}

class sfdc_AssetDataWrapper {
  public $email;//string
  public $productCode;//string
  public $purchaseDate;//string
  public $serialNumber;//string
}

class sfdc_ServiceDataWrapper {
  public $assetInfo;//Asset
  public $Status;//string
}

class sfdc_createAsset {
  public $assetWrapper;//AssetDataWrapper
}

class sfdc_createAssetResponse {
  public $result;//ServiceDataWrapper
}

class sfdc_getAssets {
  public $contactEmail;//string
}

class sfdc_getAssetsResponse {
  public $result;//Asset
}

class sfdc_getCase {
  public $caseNumber;//string
}

class sfdc_getCaseResponse {
  public $result;//Case
}

class sfdc_getCases {
  public $contactEmail;//string
  public $numberOfDays;//int
}

class sfdc_getCasesResponse {
  public $result;//Case
}

class sfdc_getContact {
  public $contactEmail;//string
}

class sfdc_getContactResponse {
  public $result;//Contact
}

class sfdc_getGoldContracts {
  public $goldNumber;//string
  public $goldPIN;//string
}

class sfdc_getGoldContractsResponse {
  public $result;//ContractLineItem
}

class sfdc_getProductFamilies {
}

class sfdc_getProductFamiliesResponse {
  public $result;//AMS_Product_Family__c
}

class sfdc_getWebProducts {
}

class sfdc_getWebProductsResponse {
  public $result;//Product2
}

class sfdc_insertCase {
  public $drupalCase;//Case
}

class sfdc_insertCaseResponse {
  public $result;//string
}

class sfdc_insertCaseComment {
  public $caseNumber;//string
  public $drupalCaseComment;//CaseComment
}

class sfdc_insertCaseCommentResponse {
}

class sfdc_insertContact {
  public $drupalContact;//Contact
}

class sfdc_insertContactResponse {
  public $result;//ID
}

class sfdc_updateContact {
  public $drupalContact;//Contact
}

class sfdc_updateContactResponse {
}

class sfdc_validateGold {
  public $goldNumber;//string
  public $goldPIN;//string
}

class sfdc_validateGoldResponse {
  public $result;//string
}

class sfdc_FNETDataService {
  public $soapClient;

  private static $classmap = array(
    'AllowFieldTruncationHeader' => 'sfdc_AllowFieldTruncationHeader',
    'CallOptions' => 'sfdc_CallOptions',
    'DebuggingHeader' => 'sfdc_DebuggingHeader',
    'LogInfo' => 'sfdc_LogInfo',
    'DebuggingInfo' => 'sfdc_DebuggingInfo',
    'SessionHeader' => 'sfdc_SessionHeader',
    'QueryResult' => 'sfdc_QueryResult',
    'sObject' => 'sfdc_sObject',
    'AMS_Product_Family__History' => 'sfdc_AMS_Product_Family__History',
    'AMS_Product_Family__c' => 'sfdc_AMS_Product_Family__c',
    'Account' => 'sfdc_Account',
    'AccountContactRole' => 'sfdc_AccountContactRole',
    'AccountContact__History' => 'sfdc_AccountContact__History',
    'AccountContact__c' => 'sfdc_AccountContact__c',
    'AccountFeed' => 'sfdc_AccountFeed',
    'AccountHistory' => 'sfdc_AccountHistory',
    'AccountPartner' => 'sfdc_AccountPartner',
    'AccountShare' => 'sfdc_AccountShare',
    'ActivityHistory' => 'sfdc_ActivityHistory',
    'AdditionalNumber' => 'sfdc_AdditionalNumber',
    'ApexClass' => 'sfdc_ApexClass',
    'ApexComponent' => 'sfdc_ApexComponent',
    'ApexLog' => 'sfdc_ApexLog',
    'ApexPage' => 'sfdc_ApexPage',
    'ApexTestQueueItem' => 'sfdc_ApexTestQueueItem',
    'ApexTestResult' => 'sfdc_ApexTestResult',
    'ApexTrigger' => 'sfdc_ApexTrigger',
    'Approval' => 'sfdc_Approval',
    'Asset' => 'sfdc_Asset',
    'AssetCreationRule__History' => 'sfdc_AssetCreationRule__History',
    'AssetCreationRule__c' => 'sfdc_AssetCreationRule__c',
    'AssetFeed' => 'sfdc_AssetFeed',
    'AssetHistory' => 'sfdc_AssetHistory',
    'AssetHistory_Custom__History' => 'sfdc_AssetHistory_Custom__History',
    'AssetHistory_Custom__c' => 'sfdc_AssetHistory_Custom__c',
    'AssignmentRule' => 'sfdc_AssignmentRule',
    'AsyncApexJob' => 'sfdc_AsyncApexJob',
    'Attachment' => 'sfdc_Attachment',
    'AuthProvider' => 'sfdc_AuthProvider',
    'BrandTemplate' => 'sfdc_BrandTemplate',
    'BusinessHours' => 'sfdc_BusinessHours',
    'BusinessProcess' => 'sfdc_BusinessProcess',
    'CallCenter' => 'sfdc_CallCenter',
    'Campaign' => 'sfdc_Campaign',
    'CampaignFeed' => 'sfdc_CampaignFeed',
    'CampaignMember' => 'sfdc_CampaignMember',
    'CampaignMemberStatus' => 'sfdc_CampaignMemberStatus',
    'CampaignShare' => 'sfdc_CampaignShare',
    'Case' => 'sfdc_SupportCase',
    'CaseComment' => 'sfdc_CaseComment',
    'CaseContactRole' => 'sfdc_CaseContactRole',
    'CaseFeed' => 'sfdc_CaseFeed',
    'CaseHistory' => 'sfdc_CaseHistory',
    'CaseMilestone' => 'sfdc_CaseMilestone',
    'CaseShare' => 'sfdc_CaseShare',
    'CaseSolution' => 'sfdc_CaseSolution',
    'CaseStatus' => 'sfdc_CaseStatus',
    'CaseTeamMember' => 'sfdc_CaseTeamMember',
    'CaseTeamRole' => 'sfdc_CaseTeamRole',
    'CaseTeamTemplate' => 'sfdc_CaseTeamTemplate',
    'CaseTeamTemplateMember' => 'sfdc_CaseTeamTemplateMember',
    'CaseTeamTemplateRecord' => 'sfdc_CaseTeamTemplateRecord',
    'CategoryData' => 'sfdc_CategoryData',
    'CategoryNode' => 'sfdc_CategoryNode',
    'ChatterActivity' => 'sfdc_ChatterActivity',
    'ChatterConversation' => 'sfdc_ChatterConversation',
    'ChatterConversationMember' => 'sfdc_ChatterConversationMember',
    'ChatterMessage' => 'sfdc_ChatterMessage',
    'ClientBrowser' => 'sfdc_ClientBrowser',
    'CollaborationGroup' => 'sfdc_CollaborationGroup',
    'CollaborationGroupFeed' => 'sfdc_CollaborationGroupFeed',
    'CollaborationGroupMember' => 'sfdc_CollaborationGroupMember',
    'CollaborationGroupMemberRequest' => 'sfdc_CollaborationGroupMemberRequest',
    'CollaborationInvitation' => 'sfdc_CollaborationInvitation',
    'Community' => 'sfdc_Community',
    'CompanyOnyx__History' => 'sfdc_CompanyOnyx__History',
    'CompanyOnyx__c' => 'sfdc_CompanyOnyx__c',
    'Contact' => 'sfdc_Contact',
    'ContactFeed' => 'sfdc_ContactFeed',
    'ContactHistory' => 'sfdc_ContactHistory',
    'ContactLead__History' => 'sfdc_ContactLead__History',
    'ContactLead__c' => 'sfdc_ContactLead__c',
    'ContactShare' => 'sfdc_ContactShare',
    'ContentDocument' => 'sfdc_ContentDocument',
    'ContentDocumentFeed' => 'sfdc_ContentDocumentFeed',
    'ContentDocumentHistory' => 'sfdc_ContentDocumentHistory',
    'ContentDocumentLink' => 'sfdc_ContentDocumentLink',
    'ContentVersion' => 'sfdc_ContentVersion',
    'ContentVersionHistory' => 'sfdc_ContentVersionHistory',
    'Contract' => 'sfdc_Contract',
    'ContractContactRole' => 'sfdc_ContractContactRole',
    'ContractFeed' => 'sfdc_ContractFeed',
    'ContractHistory' => 'sfdc_ContractHistory',
    'ContractLineItem' => 'sfdc_ContractLineItem',
    'ContractLineItemHistory' => 'sfdc_ContractLineItemHistory',
    'ContractStatus' => 'sfdc_ContractStatus',
    'CronTrigger' => 'sfdc_CronTrigger',
    'CurrencyType' => 'sfdc_CurrencyType',
    'CustomConsoleComponent' => 'sfdc_CustomConsoleComponent',
    'CustomerProductOnyx2__History' => 'sfdc_CustomerProductOnyx2__History',
    'CustomerProductOnyx2__c' => 'sfdc_CustomerProductOnyx2__c',
    'CustomerProductOnyx__History' => 'sfdc_CustomerProductOnyx__History',
    'CustomerProductOnyx__c' => 'sfdc_CustomerProductOnyx__c',
    'CustomerProductSFDC__History' => 'sfdc_CustomerProductSFDC__History',
    'CustomerProductSFDC__c' => 'sfdc_CustomerProductSFDC__c',
    'Dashboard' => 'sfdc_Dashboard',
    'DashboardComponent' => 'sfdc_DashboardComponent',
    'DashboardComponentFeed' => 'sfdc_DashboardComponentFeed',
    'DashboardFeed' => 'sfdc_DashboardFeed',
    'DatedConversionRate' => 'sfdc_DatedConversionRate',
    'Device_User__History' => 'sfdc_Device_User__History',
    'Device_User__c' => 'sfdc_Device_User__c',
    'Document' => 'sfdc_Document',
    'DocumentAttachmentMap' => 'sfdc_DocumentAttachmentMap',
    'Domain' => 'sfdc_Domain',
    'DomainSite' => 'sfdc_DomainSite',
    'EmailMessage' => 'sfdc_EmailMessage',
    'EmailServicesAddress' => 'sfdc_EmailServicesAddress',
    'EmailServicesFunction' => 'sfdc_EmailServicesFunction',
    'EmailStatus' => 'sfdc_EmailStatus',
    'EmailTemplate' => 'sfdc_EmailTemplate',
    'Entitlement' => 'sfdc_Entitlement',
    'EntitlementContact' => 'sfdc_EntitlementContact',
    'EntitlementFeed' => 'sfdc_EntitlementFeed',
    'EntitlementHistory' => 'sfdc_EntitlementHistory',
    'EntitlementTemplate' => 'sfdc_EntitlementTemplate',
    'EntitySubscription' => 'sfdc_EntitySubscription',
    'Event' => 'sfdc_Event',
    'EventFeed' => 'sfdc_EventFeed',
    'EventRecurrenceException' => 'sfdc_EventRecurrenceException',
    'EventRelation' => 'sfdc_EventRelation',
    'ExternalDataSource' => 'sfdc_ExternalDataSource',
    'ExternalDataUserAuth' => 'sfdc_ExternalDataUserAuth',
    'FNET_Custom_Settings__c' => 'sfdc_FNET_Custom_Settings__c',
    'FeedComment' => 'sfdc_FeedComment',
    'FeedItem' => 'sfdc_FeedItem',
    'FeedLike' => 'sfdc_FeedLike',
    'FeedTrackedChange' => 'sfdc_FeedTrackedChange',
    'FieldPermissions' => 'sfdc_FieldPermissions',
    'Field_Trip__Field_Analysis__History' => 'sfdc_Field_Trip__Field_Analysis__History',
    'Field_Trip__Field_Analysis__c' => 'sfdc_Field_Trip__Field_Analysis__c',
    'Field_Trip__Object_Analysis__History' => 'sfdc_Field_Trip__Object_Analysis__History',
    'Field_Trip__Object_Analysis__Share' => 'sfdc_Field_Trip__Object_Analysis__Share',
    'Field_Trip__Object_Analysis__c' => 'sfdc_Field_Trip__Object_Analysis__c',
    'FiscalYearSettings' => 'sfdc_FiscalYearSettings',
    'Folder' => 'sfdc_Folder',
    'ForecastShare' => 'sfdc_ForecastShare',
    'Gold_Email_Template__History' => 'sfdc_Gold_Email_Template__History',
    'Gold_Email_Template__c' => 'sfdc_Gold_Email_Template__c',
    'Group' => 'sfdc_Group',
    'GroupMember' => 'sfdc_GroupMember',
    'HashtagDefinition' => 'sfdc_HashtagDefinition',
    'Holiday' => 'sfdc_Holiday',
    'Idea' => 'sfdc_Idea',
    'IdeaComment' => 'sfdc_IdeaComment',
    'IndividualOnyx__History' => 'sfdc_IndividualOnyx__History',
    'IndividualOnyx__c' => 'sfdc_IndividualOnyx__c',
    'Lead' => 'sfdc_Lead',
    'LeadFeed' => 'sfdc_LeadFeed',
    'LeadHistory' => 'sfdc_LeadHistory',
    'LeadLead__History' => 'sfdc_LeadLead__History',
    'LeadLead__c' => 'sfdc_LeadLead__c',
    'LeadShare' => 'sfdc_LeadShare',
    'LeadStatus' => 'sfdc_LeadStatus',
    'LineitemOverride' => 'sfdc_LineitemOverride',
    'LoginHistory' => 'sfdc_LoginHistory',
    'LoginIp' => 'sfdc_LoginIp',
    'MQL_History__History' => 'sfdc_MQL_History__History',
    'MQL_History__c' => 'sfdc_MQL_History__c',
    'MailmergeTemplate' => 'sfdc_MailmergeTemplate',
    'MilestoneType' => 'sfdc_MilestoneType',
    'Name' => 'sfdc_Name',
    'Note' => 'sfdc_Note',
    'NoteAndAttachment' => 'sfdc_NoteAndAttachment',
    'ObjectPermissions' => 'sfdc_ObjectPermissions',
    'OnyxAccountSequence__History' => 'sfdc_OnyxAccountSequence__History',
    'OnyxAccountSequence__c' => 'sfdc_OnyxAccountSequence__c',
    'OnyxAssetSequence__History' => 'sfdc_OnyxAssetSequence__History',
    'OnyxAssetSequence__c' => 'sfdc_OnyxAssetSequence__c',
    'OnyxContactSequence__History' => 'sfdc_OnyxContactSequence__History',
    'OnyxContactSequence__c' => 'sfdc_OnyxContactSequence__c',
    'OpenActivity' => 'sfdc_OpenActivity',
    'Opportunity' => 'sfdc_Opportunity',
    'OpportunityCompetitor' => 'sfdc_OpportunityCompetitor',
    'OpportunityContactRole' => 'sfdc_OpportunityContactRole',
    'OpportunityContactRole__History' => 'sfdc_OpportunityContactRole__History',
    'OpportunityContactRole__c' => 'sfdc_OpportunityContactRole__c',
    'OpportunityFeed' => 'sfdc_OpportunityFeed',
    'OpportunityFieldHistory' => 'sfdc_OpportunityFieldHistory',
    'OpportunityHistory' => 'sfdc_OpportunityHistory',
    'OpportunityLineItem' => 'sfdc_OpportunityLineItem',
    'OpportunityOrder__History' => 'sfdc_OpportunityOrder__History',
    'OpportunityOrder__c' => 'sfdc_OpportunityOrder__c',
    'OpportunityOverride' => 'sfdc_OpportunityOverride',
    'OpportunityPartner' => 'sfdc_OpportunityPartner',
    'OpportunityShare' => 'sfdc_OpportunityShare',
    'OpportunityStage' => 'sfdc_OpportunityStage',
    'OpportunityTeamMember' => 'sfdc_OpportunityTeamMember',
    'Opportunity_History__History' => 'sfdc_Opportunity_History__History',
    'Opportunity_History__c' => 'sfdc_Opportunity_History__c',
    'Order' => 'sfdc_Order',
    'OrderContactRole__History' => 'sfdc_OrderContactRole__History',
    'OrderContactRole__c' => 'sfdc_OrderContactRole__c',
    'OrderHistory' => 'sfdc_OrderHistory',
    'OrderItem' => 'sfdc_OrderItem',
    'OrderItemHistory' => 'sfdc_OrderItemHistory',
    'OrderPartner__History' => 'sfdc_OrderPartner__History',
    'OrderPartner__c' => 'sfdc_OrderPartner__c',
    'OrgWideEmailAddress' => 'sfdc_OrgWideEmailAddress',
    'Organization' => 'sfdc_Organization',
    'Partner' => 'sfdc_Partner',
    'PartnerRole' => 'sfdc_PartnerRole',
    'Period' => 'sfdc_Period',
    'PermissionSet' => 'sfdc_PermissionSet',
    'PermissionSetAssignment' => 'sfdc_PermissionSetAssignment',
    'Pricebook2' => 'sfdc_Pricebook2',
    'Pricebook2History' => 'sfdc_Pricebook2History',
    'PricebookEntry' => 'sfdc_PricebookEntry',
    'ProcessDefinition' => 'sfdc_ProcessDefinition',
    'ProcessInstance' => 'sfdc_ProcessInstance',
    'ProcessInstanceHistory' => 'sfdc_ProcessInstanceHistory',
    'ProcessInstanceStep' => 'sfdc_ProcessInstanceStep',
    'ProcessInstanceWorkitem' => 'sfdc_ProcessInstanceWorkitem',
    'ProcessNode' => 'sfdc_ProcessNode',
    'Product2' => 'sfdc_Product2',
    'Product2Feed' => 'sfdc_Product2Feed',
    'ProductEntitlementTemplate' => 'sfdc_ProductEntitlementTemplate',
    'ProductGoldJunction__History' => 'sfdc_ProductGoldJunction__History',
    'ProductGoldJunction__c' => 'sfdc_ProductGoldJunction__c',
    'Product_Relation__History' => 'sfdc_Product_Relation__History',
    'Product_Relation__c' => 'sfdc_Product_Relation__c',
    'Profile' => 'sfdc_Profile',
    'PushTopic' => 'sfdc_PushTopic',
    'QuantityForecast' => 'sfdc_QuantityForecast',
    'QuantityForecastHistory' => 'sfdc_QuantityForecastHistory',
    'QueueSobject' => 'sfdc_QueueSobject',
    'Quote' => 'sfdc_Quote',
    'QuoteDocument' => 'sfdc_QuoteDocument',
    'QuoteFeed' => 'sfdc_QuoteFeed',
    'QuoteLineItem' => 'sfdc_QuoteLineItem',
    'QuoteTemplateRichTextData' => 'sfdc_QuoteTemplateRichTextData',
    'RecordType' => 'sfdc_RecordType',
    'Ref_Country_to_Sales_Region__History' => 'sfdc_Ref_Country_to_Sales_Region__History',
    'Ref_Country_to_Sales_Region__c' => 'sfdc_Ref_Country_to_Sales_Region__c',
    'Report' => 'sfdc_Report',
    'ReportFeed' => 'sfdc_ReportFeed',
    'RevenueForecast' => 'sfdc_RevenueForecast',
    'RevenueForecastHistory' => 'sfdc_RevenueForecastHistory',
    'SDOC__SDField__c' => 'sfdc_SDOC__SDField__c',
    'SDOC__SDRelationship__c' => 'sfdc_SDOC__SDRelationship__c',
    'SDOC__SDTemplate__History' => 'sfdc_SDOC__SDTemplate__History',
    'SDOC__SDTemplate__c' => 'sfdc_SDOC__SDTemplate__c',
    'SDOC__SDoc__History' => 'sfdc_SDOC__SDoc__History',
    'SDOC__SDoc__c' => 'sfdc_SDOC__SDoc__c',
    'Sales_Coach_Activity__c' => 'sfdc_Sales_Coach_Activity__c',
    'Sales_Coach_Admin__c' => 'sfdc_Sales_Coach_Admin__c',
    'Sales_Coach_Role__History' => 'sfdc_Sales_Coach_Role__History',
    'Sales_Coach_Role__c' => 'sfdc_Sales_Coach_Role__c',
    'Sales_Coach_Section_Item__History' => 'sfdc_Sales_Coach_Section_Item__History',
    'Sales_Coach_Section_Item__c' => 'sfdc_Sales_Coach_Section_Item__c',
    'Sales_Coach_Section__History' => 'sfdc_Sales_Coach_Section__History',
    'Sales_Coach_Section__c' => 'sfdc_Sales_Coach_Section__c',
    'Sales_Coach_Stage__History' => 'sfdc_Sales_Coach_Stage__History',
    'Sales_Coach_Stage__c' => 'sfdc_Sales_Coach_Stage__c',
    'Sales_Region__History' => 'sfdc_Sales_Region__History',
    'Sales_Region__c' => 'sfdc_Sales_Region__c',
    'Scontrol' => 'sfdc_Scontrol',
    'SelfServiceUser' => 'sfdc_SelfServiceUser',
    'ServiceContract' => 'sfdc_ServiceContract',
    'ServiceContractFeed' => 'sfdc_ServiceContractFeed',
    'ServiceContractHistory' => 'sfdc_ServiceContractHistory',
    'ServiceContractHistory_Custom__History' => 'sfdc_ServiceContractHistory_Custom__History',
    'ServiceContractHistory_Custom__c' => 'sfdc_ServiceContractHistory_Custom__c',
    'ServiceContractShare' => 'sfdc_ServiceContractShare',
    'SetupEntityAccess' => 'sfdc_SetupEntityAccess',
    'Site' => 'sfdc_Site',
    'SiteFeed' => 'sfdc_SiteFeed',
    'SiteHistory' => 'sfdc_SiteHistory',
    'SlaProcess' => 'sfdc_SlaProcess',
    'Solution' => 'sfdc_Solution',
    'SolutionFeed' => 'sfdc_SolutionFeed',
    'SolutionHistory' => 'sfdc_SolutionHistory',
    'SolutionStatus' => 'sfdc_SolutionStatus',
    'StaticResource' => 'sfdc_StaticResource',
    'Task' => 'sfdc_Task',
    'TaskAssignment__c' => 'sfdc_TaskAssignment__c',
    'TaskFeed' => 'sfdc_TaskFeed',
    'TaskPriority' => 'sfdc_TaskPriority',
    'TaskRecurrenceException' => 'sfdc_TaskRecurrenceException',
    'TaskStatus' => 'sfdc_TaskStatus',
    'Topic' => 'sfdc_Topic',
    'User' => 'sfdc_User',
    'UserFeed' => 'sfdc_UserFeed',
    'UserLicense' => 'sfdc_UserLicense',
    'UserPreference' => 'sfdc_UserPreference',
    'UserRecordAccess' => 'sfdc_UserRecordAccess',
    'UserRole' => 'sfdc_UserRole',
    'UserShare' => 'sfdc_UserShare',
    'UserTeamMember' => 'sfdc_UserTeamMember',
    'Vote' => 'sfdc_Vote',
    'WebLink' => 'sfdc_WebLink',
    'fnuCustomerGoldIdentifierOnyx__History' => 'sfdc_fnuCustomerGoldIdentifierOnyx__History',
    'fnuCustomerGoldIdentifierOnyx__c' => 'sfdc_fnuCustomerGoldIdentifierOnyx__c',
    'mkto_si__BestBetsCache__c' => 'sfdc_mkto_si__BestBetsCache__c',
    'mkto_si__Best_Bets_View_Detail__c' => 'sfdc_mkto_si__Best_Bets_View_Detail__c',
    'mkto_si__Best_Bets_View__c' => 'sfdc_mkto_si__Best_Bets_View__c',
    'mkto_si__EmailActivityCache__c' => 'sfdc_mkto_si__EmailActivityCache__c',
    'mkto_si__GroupedWebActivityCache__c' => 'sfdc_mkto_si__GroupedWebActivityCache__c',
    'mkto_si__InterestingMomentsCache__c' => 'sfdc_mkto_si__InterestingMomentsCache__c',
    'mkto_si__MarketoSettings__c' => 'sfdc_mkto_si__MarketoSettings__c',
    'mkto_si__Marketo_Sales_Insight_Config__History' => 'sfdc_mkto_si__Marketo_Sales_Insight_Config__History',
    'mkto_si__Marketo_Sales_Insight_Config__c' => 'sfdc_mkto_si__Marketo_Sales_Insight_Config__c',
    'mkto_si__ScoringCache__c' => 'sfdc_mkto_si__ScoringCache__c',
    'mkto_si__UserPreferences__c' => 'sfdc_mkto_si__UserPreferences__c',
    'mkto_si__Value__c' => 'sfdc_mkto_si__Value__c',
    'mkto_si__WebActivityCache__c' => 'sfdc_mkto_si__WebActivityCache__c',
    'qbdialer__DialerQueryAttendee__c' => 'sfdc_qbdialer__DialerQueryAttendee__c',
    'qbdialer__DialerQueryItem__c' => 'sfdc_qbdialer__DialerQueryItem__c',
    'qbdialer__DialerQuery__c' => 'sfdc_qbdialer__DialerQuery__c',
    'qbdialer__SeekInitiativeAttendee__c' => 'sfdc_qbdialer__SeekInitiativeAttendee__c',
    'qbdialer__SeekInitiativeItem__c' => 'sfdc_qbdialer__SeekInitiativeItem__c',
    'qbdialer__SeekInitiative__c' => 'sfdc_qbdialer__SeekInitiative__c',
    'qbdialer__UserStatusLog__c' => 'sfdc_qbdialer__UserStatusLog__c',
    'qbdialer__isDialerConfig__c' => 'sfdc_qbdialer__isDialerConfig__c',
    'quotesync__QuoteLineSyncField__c' => 'sfdc_quotesync__QuoteLineSyncField__c',
    'quotesync__QuoteSyncField__c' => 'sfdc_quotesync__QuoteSyncField__c',
    'AssetDataWrapper' => 'sfdc_AssetDataWrapper',
    'ServiceDataWrapper' => 'sfdc_ServiceDataWrapper',
    'createAsset' => 'sfdc_createAsset',
    'createAssetResponse' => 'sfdc_createAssetResponse',
    'getAssets' => 'sfdc_getAssets',
    'getAssetsResponse' => 'sfdc_getAssetsResponse',
    'getCase' => 'sfdc_getCase',
    'getCaseResponse' => 'sfdc_getCaseResponse',
    'getCases' => 'sfdc_getCases',
    'getCasesResponse' => 'sfdc_getCasesResponse',
    'getContact' => 'sfdc_getContact',
    'getContactResponse' => 'sfdc_getContactResponse',
    'getGoldContracts' => 'sfdc_getGoldContracts',
    'getGoldContractsResponse' => 'sfdc_getGoldContractsResponse',
    'getProductFamilies' => 'sfdc_getProductFamilies',
    'getProductFamiliesResponse' => 'sfdc_getProductFamiliesResponse',
    'getWebProducts' => 'sfdc_getWebProducts',
    'getWebProductsResponse' => 'sfdc_getWebProductsResponse',
    'insertCase' => 'sfdc_insertCase',
    'insertCaseResponse' => 'sfdc_insertCaseResponse',
    'insertCaseComment' => 'sfdc_insertCaseComment',
    'insertCaseCommentResponse' => 'sfdc_insertCaseCommentResponse',
    'insertContact' => 'sfdc_insertContact',
    'insertContactResponse' => 'sfdc_insertContactResponse',
    'updateContact' => 'sfdc_updateContact',
    'updateContactResponse' => 'sfdc_updateContactResponse',
    'validateGold' => 'sfdc_validateGold',
    'validateGoldResponse' => 'sfdc_validateGoldResponse'

  );

  function __construct($url = 'FNETDataService.wsdl') {
    $this->soapClient = new SoapClient($url, array(
      "classmap" => self::$classmap,
      "trace" => TRUE,
      "exceptions" => TRUE,
      "cache_wsdl" => WSDL_CACHE_NONE,

    ));
  }

  function createAsset($createAsset) {

    $createAssetResponse = $this->soapClient->createAsset($createAsset);
    return $createAssetResponse;

  }

  function getAssets($getAssets) {

    $getAssetsResponse = $this->soapClient->getAssets($getAssets);
    return $getAssetsResponse;

  }

  function getCase($getCase) {

    $getCaseResponse = $this->soapClient->getCase($getCase);
    return $getCaseResponse;

  }

  function getCases($getCases) {

    $getCasesResponse = $this->soapClient->getCases($getCases);
    return $getCasesResponse;

  }

  function getContact($getContact) {

    $getContactResponse = $this->soapClient->getContact($getContact);
    return $getContactResponse;

  }

  function getGoldContracts($getGoldContracts) {

    $getGoldContractsResponse = $this->soapClient->getGoldContracts($getGoldContracts);
    return $getGoldContractsResponse;

  }

  function getProductFamilies($getProductFamilies) {

    $getProductFamiliesResponse = $this->soapClient->getProductFamilies($getProductFamilies);
    return $getProductFamiliesResponse;

  }

  function getWebProducts($getWebProducts) {

    $getWebProductsResponse = $this->soapClient->getWebProducts($getWebProducts);
    return $getWebProductsResponse;

  }

  function insertCase($insertCase) {

    $insertCaseResponse = $this->soapClient->insertCase($insertCase);
    return $insertCaseResponse;

  }

  function insertCaseComment($insertCaseComment) {

    $insertCaseCommentResponse = $this->soapClient->insertCaseComment($insertCaseComment);
    return $insertCaseCommentResponse;

  }

  function insertContact($insertContact) {

    $insertContactResponse = $this->soapClient->insertContact($insertContact);
    return $insertContactResponse;

  }

  function updateContact($updateContact) {

    $updateContactResponse = $this->soapClient->updateContact($updateContact);
    return $updateContactResponse;

  }

  function validateGold($validateGold) {

    $validateGoldResponse = $this->soapClient->validateGold($validateGold);
    return $validateGoldResponse;

  }
}
